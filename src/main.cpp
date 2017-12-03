#include <RFM69.h>
#include <RbC_Motors.h>
#include <SPI.h>
#include <defines.h>
#include <pinout.h>
#include <vector>
// #include <SPIFlash.h>

using namespace std;
RFM69 radio;
Motor motor;
Robot robot;
// SPIFlash flash(8, 0xEF30); //EF40 for 16mbit windbond chip
byte ackCount = 0;

byte data[61];
vector<byte> received;

typedef struct {
  uint16_t ID;
  int pwm2; // store this nodeId
  int pwm1;
} Payload;
Payload theData;

void setup() {
  Serial.begin(SERIAL_BAUD);
  delay(10);
  radio.initialize(FREQUENCY, NODEID, NETWORKID);
#ifdef IS_RFM69HW_HCW
  radio.setHighPower(); // must include this only for RFM69HW/HCW!
#endif
  radio.encrypt(KEY);
  radio.promiscuous(PROMISCUOUS_MODE);
  char buff[50];
  sprintf(buff, "\nListening at %d Mhz...", FREQUENCY == RF69_433MHZ ? 433 : FREQUENCY == RF69_868MHZ ? 868 : 915);
  Serial.println(buff);
}

void blink(byte pin, int delay_ms) {
  pinMode(pin, OUTPUT);
  digitalWrite(pin, HIGH);
  delay(delay_ms);
  digitalWrite(pin, LOW);
}

void ping() {
  if (radio.ACKRequested()) {
    byte theNodeID = radio.SENDERID;
    radio.sendACK();
    print(" - ACK sent.");

    // When a node requests an ACK, respond to the ACK
    // and also send a packet requesting an ACK (every 3rd one only)
    // This way both TX/RX NODE functions are tested on 1 end at the GATEWAY
    if (ackCount++ % 3 == 0) {
      print(" Pinging node ");
      print(theNodeID);
      print(" - ACK...");
      delay(3);                                             // need this when sending right after reception .. ?
      if (radio.sendWithRetry(theNodeID, "ACK TEST", 8, 0)) // 0 = only 1 attempt, no retries
        print("ok!");
      else
        print("nothing");
    }
  }
  print("\n");
}

void show_debug_data() {
  print("[FROM:");
  print(radio.SENDERID);
  print("] ");
  print(" [RX_RSSI:");
  print(radio.readRSSI());
  print("]");
  if (PROMISCUOUS_MODE) {
    print("to [");
    print(radio.TARGETID);
    print("] ");
  }
}

void loop() {
  // process any serial input
  if (radio.receiveDone()) {
    show_debug_data();
    if (radio.DATALEN == 6) {
      theData = *(Payload *)radio.DATA;
      print(" M1_DIR = ");
      if (theData.pwm1 < 0) {
        print(motor.Set_Direction_motor1(BACKWARD));
      } else if (theData.pwm1 > 0) {
        print(motor.Set_Direction_motor1(FORWARD));
      } else {
        print(motor.Set_Direction_motor1(STOP));
      }
      print(" M1_DIR = ");
      if (theData.pwm2 < 0) {
        print(motor.Set_Direction_motor2(BACKWARD));
      } else if (theData.pwm2 > 0) {
        print(motor.Set_Direction_motor2(FORWARD));
      } else {
        print(motor.Set_Direction_motor2(STOP));
      }

      print("\t M1_PWM = ");
      print(motor.Set_PWM1(abs(theData.pwm1)));
      print("\t M2_PWM = ");
      print(motor.Set_PWM2(abs(theData.pwm2)));
      motor.Write_Directions();
      motor.Write_PWM1();
      motor.Write_PWM2();

    } else {
      for (int i = 0; i < radio.DATALEN; i++) { // loop through all the new bytes
        // data[i] = radio.DATA[i];
        // Serial.println();
        // print(" ");
        // print(radio.DATA[i]);
        Serial.write(radio.DATA[i]);
      }
    }

    ping();
    blink(LED, 3);
  }
}
