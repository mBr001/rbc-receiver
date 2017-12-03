#ifndef PINOUT_CPP
#define PINOUT_CPP

#include <pinout.h>

Servo SRV1;


void Default_Init_Pin_2_0() {
  pinMode(DIR1_1_PIN, OUTPUT);
  pinMode(DIR1_2_PIN, OUTPUT);
  pinMode(DIR2_1_PIN, OUTPUT);
  pinMode(DIR2_2_PIN, OUTPUT);
  pinMode(PWM1_PIN, OUTPUT);
  pinMode(SRV1_PIN, OUTPUT);
  pinMode(NSS_PIN, OUTPUT);
  pinMode(MOSI_PIN, OUTPUT);
  pinMode(MISO_PIN, OUTPUT);
  pinMode(SCK_PIN, OUTPUT);
}

#endif