#include <my_rp_4wd.h>
#include <Wire.h>
#include <EEPROM.h>
#define EEPROM_ADDR 0x50
#include <my_mpu6050.h> 

float rot, high, low;
float theta1,theta2,theta3;
#define ROBOT_ARM_LOW 140
#define ROBOT_ARM_HIGH 140
#define ROBOT_ARM_EE_OFFSET 0

int servo_tim23 = 0;
int servo_tim22 = 0;

// Number of steps
int num_steps = 20;

// Initial angles
float s22_before_deg = 90 + servo_tim22;
float s23_before_deg = 90 + servo_tim23;
float s28_before_deg = 0 ;

int ch_x;
  
unsigned long lasts_time=millis();
//------------------------->>

int sensor_maxs[] = {954, 966, 925, 995, 766, 955, 941, 922}; 
int sensor_mins[] = {289, 231, 175, 186, 182, 164, 189, 184}; 


void setup()
  {    
     Serial.begin(9600);
     sensor_set();              // ค่าเริ่มต้น eeprom, bit_analogRead=>12   
     setup_mpu();
     calibration_Yak();
     mydisplay_background(black);
     mydisplay("MY-MAKERS", 20, 30, 2, white);
     pinMode(27,INPUT_PULLUP);

     servo(23, s23_before_deg);
     servo(22, s22_before_deg);
     sw_start();    
         //cal_censor(0, 0);sw();
         //test_line_r();
         
//\\------------------------------------------->>>>>  เขียนโค๊ดที่นี้ 

//Motor(50, 50, 50, 50);delay(3000);

    robot_FW_line(50, 0.5, 1);
    robot_TR(70, 10);
    robot_FW_line(50, 0.5, 1);
    robot_TR(70, 10);
/*
for(int i=0; i<2; i++)
  {
    co_xyz(0, 140, 140, 5);delay(1000);
    co_xyz(0, 140, 0, 15);delay(1000);
    co_xyz(140, 140, 140, 5);delay(1000);
    co_xyz(0, 140, 0, 5);delay(1000);
    co_xyz(-100, 200, -60, 5);delay(1000);
    co_xyz(0, 140, 140, 5);delay(1000);

    move_R(50, 1000);delay(300);
    calibration_Yak();
    co_xyz(0, 140, 0, 15);delay(1000);
    co_xyz(140, 140, 140, 5);delay(1000);
    co_xyz(0, 140, 0, 5);delay(1000);
    co_xyz(-100, 200, -60, 5);delay(1000);
    co_xyz(0, 140, 140, 5);delay(1000);
    move_L(50, 1000);delay(300);calibration_Yak();
  }
 */ 
/*
   co_xyz(40, 50, 30); delay(1000);

   fw(50, 1000);delay(300);
    move_L(50, 1000);delay(300);
    move_R(50, 1000);delay(300);
    bw(50, 1000);delay(300);
    fw(50, 1000);delay(300);
    move_R(50, 1000);delay(300);
    move_L(50, 1000);delay(300);
 
for(int i=0; i<2; i++)
  {
    co_xyz(200, 100, -70, 6); delay(1000);
    co_xyz(140, 140, 30); delay(1000);
    co_xyz(80, 140, 50); delay(1000);
    co_xyz(80, -20, 50); delay(1000);
    co_xyz(80, 140, 50); delay(1000);
    co_xyz(-200, 140, -70, 6);delay(1000);
    co_xyz(80, 140, 50); delay(1000);
    co_xyz(80, -20, 50); delay(1000);
    co_xyz(80, 140, 50); delay(1000);
    co_xyz(0, 140, 140, 10);delay(1000);
    move_L(50, 1000);delay(300);
    co_xyz(240, -50, 30);delay(1000);
    co_xyz(80, 140, 50); delay(1000);
    co_xyz(80, -20, 50); delay(1000);
    co_xyz(80, 140, 50); delay(1000);
    co_xyz(140, 140, 30); delay(1000);
    move_R(50, 1000);delay(300);
  }
   co_xyz(40, 50, 30); delay(1000);
   move_UT(50);
   fw(50, 2000);delay(300);
*/
/*
for(int i=0; i<3; i++)
  {
    robot_FW_line(50, 0.5, 1);
    robot_TR(70, 10);
    robot_FW_line(50, 0.5, 1);
    robot_TR(70, 10);
    robot_FW_line(50, 0.5, 1);
    robot_TR(70, 10);
    robot_FW_line(50, 0.5, 1);
    robot_TR(70, 10);
    
    robot_FW_line(50, 0.5, 1);
    robot_BW_line(50, 0.5, 1);
    robot_TL(70, 10);
    robot_BW_line(50, 0.5, 1);
    robot_TL(70, 10);
    robot_BW_line(50, 0.5, 1);
    robot_TL(70, 10);
    robot_BW_line(50, 0.5, 1);
    robot_TL(70, 10);
    robot_BW_line(50, 0.5, 1);
  }
*/
/*
    fw(50, 1000);delay(300);
    move_L(50, 1000);delay(300);
    move_R(50, 1000);delay(300);
    bw(50, 1000);delay(300);
    fw(50, 1000);delay(300);
    move_R(50, 1000);delay(300);
    move_L(50, 1000);delay(300);
 */  
//\\------------------------------------------->>>>>   เขียนโค๊ดที่นี้ 
     
      
  }

void loop() 
  {  
    //Serial.println(position_FW());
    co_a( 0, 140, 140);
    
  }
