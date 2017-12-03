#ifndef PINOUT_CPP
#define PINOUT_CPP

#include <Pinout.h>

Servo SRV1;

void Default_Init_Pin_1_1()
{
  // pinMode(LED1_PIN,OUTPUT);
  // pinMode(DIR1_1_PIN,OUTPUT);
  // pinMode(DIR1_2_PIN,OUTPUT);
  // pinMode(DIR2_1_PIN,OUTPUT);
  // pinMode(DIR2_2_PIN,OUTPUT);
  // pinMode(PWM1_PIN,OUTPUT);
  // pinMode(PWM2_PIN,OUTPUT);
  // pinMode(CE_PIN,OUTPUT);
  // pinMode(CSN_PIN,OUTPUT);
  // pinMode(MOSI_PIN, OUTPUT);
  // pinMode(MISO_PIN, OUTPUT);
  // pinMode(SCK_PIN, OUTPUT);
  // pinMode(CH1_PIN,INPUT);
  // pinMode(CH2_PIN,INPUT);
  // pinMode(GPIO1_PIN,OUTPUT);
  // pinMode(GPIO2_PIN,OUTPUT);
  // pinMode(GPIO3_PIN,OUTPUT);
  // pinMode(GPIO4_PIN,OUTPUT);
  // pinMode(GPIO5_PIN,OUTPUT);
  // pinMode(GPIO6_PIN,OUTPUT);
}
void Default_Init_Pin_2_0()
{
  // pinMode(LED1_PIN,OUTPUT);
  pinMode(DIR1_1_PIN,OUTPUT);
  pinMode(DIR1_2_PIN,OUTPUT);
  pinMode(DIR2_1_PIN,OUTPUT);
  pinMode(DIR2_2_PIN,OUTPUT);
  pinMode(PWM1_PIN,OUTPUT);
  pinMode(SRV1_PIN,OUTPUT);
  pinMode(NSS_PIN,OUTPUT);
  // pinMode(CSN_PIN,OUTPUT);
  pinMode(MOSI_PIN, OUTPUT);
  pinMode(MISO_PIN, OUTPUT);
  pinMode(SCK_PIN, OUTPUT);
  // pinMode(CH1_PIN,INPUT);
  // pinMode(CH2_PIN,INPUT);
  // pinMode(GPIO1_PIN,OUTPUT);
  // pinMode(GPIO2_PIN,OUTPUT);
  // pinMode(GPIO3_PIN,OUTPUT);
  // pinMode(GPIO4_PIN,OUTPUT);
  // pinMode(GPIO5_PIN,OUTPUT);
  // pinMode(GPIO6_PIN,OUTPUT);
}

#endif
