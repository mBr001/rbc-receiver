#ifndef RbC_MOTORS_CPP
#define RbC_MOTORS_CPP

#include <RbC_Motors.h>

Motor::Motor()
{
  this->val_DIR1 = STOP;
  this->val_DIR2 = STOP;
  this->val_PWM1 = PWM_MAX_VALUE;
  this->val_PWM2 = PWM_MAX_VALUE;
  this->val_SRV1 = SRV_MDL_VALUE;
}

Direction Motor::Set_Direction_motor1(Direction dir)
{
  if(dir == FORWARD || dir == BACKWARD || dir == STOP)
    this->val_DIR1 = dir;
  return this->val_DIR1;
}
Direction Motor::Set_Direction_motor2(Direction dir)
{
  if(dir == FORWARD || dir == BACKWARD || dir == STOP)
    this->val_DIR2 = dir;
  return this->val_DIR2;
}

int Motor::Set_PWM1(const int val)
{
  if(val <=PWM_MAX_VALUE &&  val >= PWM_MIN_VALUE){
    this->val_PWM1 = val;
  }
  else{
    this->val_PWM1 = PWM_MAX_VALUE;
  }
  return this->val_PWM1;
}
int Motor::Set_PWM2(const int val)
{
  if(val <=PWM_MAX_VALUE &&  val >= PWM_MIN_VALUE)
    this->val_PWM2 = val;
  else
    this->val_PWM2 = PWM_MAX_VALUE;

  return this->val_PWM2;
}
int Motor::Set_SRV1(const int val)
{
  if(val <= SRV_MAX_VALUE && val >= SRV_MIN_VALUE)
    this->val_SRV1 = val;
  else
    this->val_SRV1 = SRV_MDL_VALUE;
  return this->val_SRV1;

}
int Motor::Write_PWM1()
{
  analogWrite(PWM1_PIN, PWM_MAX_VALUE - this->val_PWM1);
  return this->val_PWM1;
}
int Motor::Write_PWM2()
{
  analogWrite(PWM2_PIN, PWM_MAX_VALUE - this->val_PWM2);
  return this->val_PWM2;
}
int Motor::Write_SRV1()
{
  analogWrite(SRV1_PIN, this->val_SRV1);
  return this->val_SRV1;
}

void Motor::RC_Val_2_Mot_Val_1_1(const RC_Controller c)
{
  if(!c.Get_error_occured())
  {
    this->val_PWM1 = c.Get_val_CH1();
    this->val_SRV1 = c.Get_val_CH2();
    //motor 1
    if (this->val_PWM1 >= LO_Y_AXIS && this->val_PWM1 <= DEADLO_Y_AXIS)
    {
      this->val_PWM1 = map(this->val_PWM1, LO_Y_AXIS, DEADLO_Y_AXIS, PWM_MIN_VALUE, PWM_MAX_VALUE);
      this->val_DIR1 = BACKWARD;
    }
    else if (this->val_PWM1 == CENTER_Y_AXIS)
    {
      this->val_PWM1 = PWM_MAX_VALUE;
      this->val_DIR1 = STOP;
    }
    else if (this->val_PWM1 >= DEADHI_Y_AXIS && this->val_PWM1 <= HI_Y_AXIS)
    {
      this->val_PWM1 = map(this->val_PWM1, DEADHI_Y_AXIS, HI_Y_AXIS, PWM_MAX_VALUE, PWM_MIN_VALUE);
      this->val_DIR1 = FORWARD;
    }
    //motor 2
    if (this->val_SRV1 >= LO_X_AXIS && this->val_SRV1 <= DEADLO_X_AXIS)
    {
      this->val_SRV1 = map(this->val_SRV1, LO_X_AXIS, DEADLO_X_AXIS, SRV_MIN_VALUE, SRV_MDL_VALUE);
    }
    else if (this->val_SRV1 == CENTER_X_AXIS)
    {
      this->val_SRV1 = SRV_MDL_VALUE;
    }
    else if (this->val_SRV1 >= DEADHI_X_AXIS && this->val_SRV1 <= HI_X_AXIS)
    {
      this->val_SRV1 = map(this->val_SRV1, DEADHI_X_AXIS, HI_X_AXIS, SRV_MDL_VALUE, SRV_MAX_VALUE);
    }
  }
}

void Motor::Write_Directions()
{
  if(this->val_DIR1 == STOP)
  {
    digitalWrite(DIR1_1_PIN, LOW);
    digitalWrite(DIR1_2_PIN, LOW);
  }
  else if(this->val_DIR1 == FORWARD)
  {
    digitalWrite(DIR1_1_PIN, HIGH);
    digitalWrite(DIR1_2_PIN, LOW);
  }
  else if(this->val_DIR1 == BACKWARD)
  {
    digitalWrite(DIR1_1_PIN, LOW);
    digitalWrite(DIR1_2_PIN, HIGH);
  }
  else
  {
    digitalWrite(DIR1_1_PIN, LOW);
    digitalWrite(DIR1_2_PIN, LOW);
  }

  if(this->val_DIR2 == STOP)
  {
    digitalWrite(DIR2_1_PIN, LOW);
    digitalWrite(DIR2_2_PIN, LOW);
  }
  else if(this->val_DIR2 == BACKWARD)
  {
    digitalWrite(DIR2_1_PIN, HIGH);
    digitalWrite(DIR2_2_PIN, LOW);
  }
  else if(this->val_DIR2 == FORWARD)
  {
    digitalWrite(DIR2_1_PIN, LOW);
    digitalWrite(DIR2_2_PIN, HIGH);
  }
  else
  {
    digitalWrite(DIR2_1_PIN, LOW);
    digitalWrite(DIR2_2_PIN, LOW);
  }
}

void Motor::RC_Val_2_Mot_Val_2_0(const RC_Controller *c)
{

}


#endif
