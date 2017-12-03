#ifndef STEROWANIE_RC_CPP
#define STEROWANIE_RC_CPP

#include <Sterowanie_RC.h>

void RC_Controller::RC_Controller_Init()
{
  this->error_occured = FALSE;
  this->val_CH1 = CENTER_Y_AXIS;
  this->val_CH2 = CENTER_X_AXIS;
}


void RC_Controller:: Read_Channel_Values()
{
  this->val_CH1 = pulseIn(CH1_PIN,HIGH,LISTENING_TIMEOUT);
  this->val_CH2 = pulseIn(CH1_PIN,HIGH,LISTENING_TIMEOUT);
  if(this->val_CH1 < ERROR_BOUND_LO || this->val_CH1 > ERROR_BOUND_HI)
    this->error_occured = TRUE;
  else if(this->val_CH2 < ERROR_BOUND_LO || this->val_CH2 > ERROR_BOUND_HI)
    this->error_occured = TRUE;
  else
    this->error_occured = FALSE;
}

void RC_Controller:: Normalize_Values()
{
  if(!this->error_occured)
  {
    //channel 1
    if(this->val_CH1 <= LO_Y_AXIS)
    {
      this->val_CH1  = LO_Y_AXIS;
    }
    if (this->val_CH1  <= DEADHI_Y_AXIS && this->val_CH1 >= DEADLO_Y_AXIS)
    {
      this->val_CH1  = CENTER_Y_AXIS;
    }
    if(this->val_CH1  >= HI_Y_AXIS)
    {
      this->val_CH1  = HI_Y_AXIS;
    }
    //channel 2
    if(this->val_CH2 <= LO_X_AXIS)
    {
      this->val_CH2  = LO_X_AXIS;
    }
    if (this->val_CH2  <= DEADHI_X_AXIS && this->val_CH2 >= DEADLO_X_AXIS)
    {
      this->val_CH2  = CENTER_X_AXIS;
    }
    if(this->val_CH2  >= HI_X_AXIS)
    {
      this->val_CH2  = HI_X_AXIS;
    }
  }
}

#endif
