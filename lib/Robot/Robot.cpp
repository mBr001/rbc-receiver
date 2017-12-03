#ifndef ROBOT_CPP
#define ROBOT_CPP

#include <Robot.h>

Robot::Robot()
{
  this->ID = DEFAUTL_ID;
  this->Type = DEAFULT_TYPE;
  this->Error_Occured = false;
}

int Robot::Set_Robot_ID(const uint16_t _ID)
{
  this->ID = _ID;
  return this->ID;
}

int Robot::Get_Robot_ID()
{
  return this->ID;
}

Robot_type Robot::Set_Robot_Type(const Robot_type _Type)
{
  this->Type = _Type;
  return this->Type;
}

Robot_type Robot::Get_Robot_Type()
{
  return this->Type;
}

#endif
