#include <Arduino.h>
#include <SPIFlash.h>
#include <RFM69.h>
#include <SPI.h>

#define NODEID 1
#define NETWORKID 100
#define FREQUENCY RF69_868MHZ  //Match this with the version of your Moteino! (others: RF69_433MHZ, RF69_868MHZ)
#define KEY "sampleEncryptKey" //has to be same 16 characters/bytes on all nodes, not more not less!
#define LED 13
#define SERIAL_BAUD 115200
#define ACK_TIME 50 // # of ms to wait for an ack
//#define IS_RFM69HW_HCW  //uncomment only for RFM69HW/HCW! Leave out if you have RFM69W/CW!

RFM69 radio;

//SPIFlash flash(8, 0xEF30); //EF40 for 16mbit windbond chip
bool promiscuousMode = false; //set to 'true' to sniff all packets on the same network
byte ackCount = 0;

typedef struct
{
    uint16_t ID;
    int pwm2; //store this nodeId
    int pwm1;
} Payload;
Payload theData;

void blink(byte PIN, int DELAY_MS) {
    pinMode(PIN, OUTPUT);
    digitalWrite(PIN, HIGH);
    delay(DELAY_MS);
    digitalWrite(PIN, LOW);
}

void setup() {
    Serial.begin(SERIAL_BAUD);
    delay(10);
    radio.initialize(FREQUENCY, NODEID, NETWORKID);
    #ifdef IS_RFM69HW_HCW
        radio.setHighPower(); //must include this only for RFM69HW/HCW!
    #endif
    radio.encrypt(KEY);
    radio.promiscuous(promiscuousMode);
    char buff[50];
    sprintf(buff, "\nListening at %d Mhz...", FREQUENCY == RF69_433MHZ ? 433 : FREQUENCY == RF69_868MHZ ? 868 : 915);
    Serial.println(buff);
}

void ping() {
    if (radio.ACKRequested()) {
        byte theNodeID = radio.SENDERID;
        radio.sendACK();
        Serial.print(" - ACK sent.");

        // When a node requests an ACK, respond to the ACK
        // and also send a packet requesting an ACK (every 3rd one only)
        // This way both TX/RX NODE functions are tested on 1 end at the GATEWAY
        if (ackCount++ % 3 == 0) {
            Serial.print(" Pinging node ");
            Serial.print(theNodeID);
            Serial.print(" - ACK...");
            delay(3);                                             //need this when sending right after reception .. ?
            if (radio.sendWithRetry(theNodeID, "ACK TEST", 8, 0)) // 0 = only 1 attempt, no retries
                Serial.print("ok!");
            else
                Serial.print("nothing");
        }
    }
}

void loop() {
    //process any serial input
    if (radio.receiveDone())
    {
        Serial.print('[');
        Serial.print(radio.SENDERID, DEC);
        Serial.print("] ");
        Serial.print(" [RX_RSSI:");
        Serial.print(radio.readRSSI());
        Serial.print("]");
        if (promiscuousMode)
        {
            Serial.print("to [");
            Serial.print(radio.TARGETID, DEC);
            Serial.print("] ");
        }

        if (radio.DATALEN != sizeof(Payload))
            Serial.print("Invalid payload received, not matching Payload struct!");
        else
        {
            theData = *(Payload *)radio.DATA; //assume radio.DATA actually contains our struct and not something else
        }
        ping();
        Serial.println();
        blink(LED, 3);
    }
}
