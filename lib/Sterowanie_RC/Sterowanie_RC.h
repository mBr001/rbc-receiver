#ifndef STEROWANIE_RC_h
#define STEROWANIE_RC_h

#include <Arduino.h>
#include <Pinout.h>
#include <RC_Controller_Settings.h>
#include <Bool.h>



class RC_Controller {
private:
  int val_CH1;  //długość impulsu z odbiornika
  int val_CH2;  //długość impulsu z odbiornika
  int error_occured; //czy wystąpił błąd
public:
  void RC_Controller_Init();
  void Read_Channel_Values();
  void Normalize_Values();
  int Get_val_CH1(){
    return this->val_CH1;
  }
  int Get_val_CH2(){
    return this->val_CH2;
  }
  int Get_error_occured(){
    return this->error_occured;
  }


};

#endif
