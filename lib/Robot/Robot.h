#ifndef ROBOT_H
#define ROBOT_H

#include <Arduino.h>
#include <Bool.h>

#define DEFAUTL_ID 0x00
#define DEAFULT_TYPE R2_0

enum Robot_type{R2_0,R1_1};
typedef Robot_type Robot_type_;

class Robot{
private:
  uint16_t ID;
  bool Error_Occured;
  Robot_type_ Type;
public:
  Robot();
  int Set_Robot_ID(const uint16_t _ID);
  int Get_Robot_ID();
  Robot_type Set_Robot_Type(const Robot_type _Type);
  Robot_type Get_Robot_Type();
};





#endif
