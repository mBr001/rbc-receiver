#include <Arduino.h>
#include <Servo.h>
#define RX_PIN 0
#define TX_PIN 1
#define INTERR_PIN 2
#define DIR2_1_PIN 7
#define DIR2_2_PIN 8
#define PWM2_PIN 5
#define PWM1_PIN 6
#define DIR1_1_PIN 4
#define DIR1_2_PIN 9
#define SRV1_PIN 6
#define NSS_PIN 10
#define MOSI_PIN 11
#define MISO_PIN 12
#define SCK_PIN 13
#define CH1_PIN -1
#define CH2_PIN -1
#define BAUD_RATE 9600

void Default_Init_Pin_2_0();

extern Servo SRV1;