#include <Arduino.h>
#include <RFM69.h>
#include <SPI.h>
//#include <SPIFlash.h>

#define NODEID 2
#define NETWORKID 100
#define FREQUENCY RF69_868MHZ  //Match this with the version of your Moteino! (others: RF69_433MHZ, RF69_868MHZ)
#define KEY "sampleEncryptKey" //has to be same 16 characters/bytes on all nodes, not more not less!
#define LED 13
#define SERIAL_BAUD 115200
#define ACK_TIME 50 // # of ms to wait for an ack

bool promiscuousMode = false; //set to 'true' to sniff all packets on the same network

RFM69 radio;

void setup() {
    Serial.begin(SERIAL_BAUD);
    radio.initialize(FREQUENCY, NODEID, NETWORKID);
    //radio.setHighPower(); //uncomment only for RFM69HW!
    radio.encrypt(KEY);
    char buff[50];
    sprintf(buff, "\nListening at %d Mhz...", FREQUENCY == RF69_433MHZ ? 433 : FREQUENCY == RF69_868MHZ ? 868 : 915);
    Serial.println(buff);
}

void loop() {
    // put your main code here, to run repeatedly:
}