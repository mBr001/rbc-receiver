#ifndef RbC_MOTORS_H
#define RbC_MOTORS_H

#include <Arduino.h>
#include <Pinout.h>
#include <Robot.h>
#include <RC_Controller_Settings.h>
#include <Sterowanie_RC.h>
#include <Bool.h>

#define PWM_MAX_VALUE 255
#define PWM_MIN_VALUE 0
#define SRV_MAX_VALUE 180
#define SRV_MDL_VALUE 90
#define SRV_MIN_VALUE 0


enum Direction {FORWARD, BACKWARD, STOP};
typedef Direction Direction;

class Motor {
private:
  int val_PWM1; //szybkość obrotów silnika  0-255
  int val_PWM2; //szybkość obrotów silnika  0-255
  int val_SRV1; //położenie serwa           0-180
  Direction val_DIR1; //kierunek obrotów silnika FORWARD, BACKWARD, STOP
  Direction val_DIR2; //kierunek obrotów silnika FORWARD, BACKWARD, STOP
public:
  /*
  *
  */
 Motor();
 /*
 *
 */
int Set_PWM1(const int val);
int Set_PWM2(const int val);
int Set_SRV1(const int val);
int Write_PWM1();
int Write_PWM2();
int Write_SRV1();
Direction Set_Direction_motor1(Direction dir);
Direction Set_Direction_motor2(Direction dir);
 /*
 *
 */
 void RC_Val_2_Mot_Val_2_0(const RC_Controller *c);
 /*
 *
 */
 void Write_Directions();
 /*
 *
 */
 void RC_Val_2_Mot_Val_1_1(const RC_Controller c);
 /*
 *
 */
 void Controll_Motors_1_1();
};

#endif
