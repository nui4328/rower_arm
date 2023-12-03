
         //float P, I, D, previous_I, previous_error,errors, PID_output, present_position, previous_integral; 
         /*
          errors = -----------;
          I = 0;
          previous_I = 0;
          previous_error = 0;
          P = errors;
          I = I + previous_I;
          D = errors - previous_error ;            
          previous_I=I;
          previous_error=errors  ;  
          PID_output = (5 * P) + (0.00015 * I) +(15* D); 
         */
float position_FW()
  {
    float position_L = map(mcp_f(0), sensor_maxs[0], sensor_mins[0], 0, 30);
    float position_R = map(mcp_f(1), sensor_maxs[1], sensor_mins[1], 0, 30);
    return position_L - position_R;
  }
void robot_FW_line(int sp, float kp, float kd)
  {
    lasts_time = millis();
        while(millis() - lasts_time < 350)
      {
          errors = position_FW();
          I = 0;
          previous_I = 0;
          previous_error = 0;
          P = errors;
          I = I + previous_I;
          D = errors - previous_error ;            
          previous_I=I;
          previous_error=errors  ;  
          PID_output = (kp * P) + (0.00015 * I) +(kd* D); 
          
          Motor(sp - PID_output, sp + PID_output, sp - PID_output, sp + PID_output); 
      }
    while(1)
      {
          errors = position_FW();
          I = 0;
          previous_I = 0;
          previous_error = 0;
          P = errors;
          I = I + previous_I;
          D = errors - previous_error ;            
          previous_I=I;
          previous_error=errors  ;  
          PID_output = (kp * P) + (0.00015 * I) +(kd* D); 
          
          Motor(sp - PID_output, sp + PID_output, sp - PID_output, sp + PID_output); 
          if(mcp_f(2)< md_sensors(2)-100|| mcp_f(3)< md_sensors(3)-100)
            {
              break;
            }
      }
    Motor(0, 0, 0, 0);delay(100);
  }

float position_BW()
  {
    float position_R = map(mcp_f(4), sensor_maxs[4], sensor_mins[4], 0, 30);
    float position_L = map(mcp_f(5), sensor_maxs[5], sensor_mins[5], 0, 30);
    return position_L - position_R;
  }
void robot_BW_line(int sp, float kp, float kd)
  {
    lasts_time = millis();
        while(millis() - lasts_time < 350)
      {
          errors = position_BW();
          I = 0;
          previous_I = 0;
          previous_error = 0;
          P = errors;
          I = I + previous_I;
          D = errors - previous_error ;            
          previous_I=I;
          previous_error=errors  ;  
          PID_output = (kp * P) + (0.00015 * I) +(kd* D); 
          
          Motor(-(sp + PID_output), -(sp - PID_output), -(sp + PID_output), -(sp - PID_output));
      }
    while(1)
      {
          errors = position_BW();
          I = 0;
          previous_I = 0;
          previous_error = 0;
          P = errors;
          I = I + previous_I;
          D = errors - previous_error ;            
          previous_I=I;
          previous_error=errors  ;  
          PID_output = (kp * P) + (0.00015 * I) +(kd* D); 
          
         Motor(-(sp + PID_output), -(sp - PID_output), -(sp + PID_output), -(sp - PID_output));
          if(mcp_f(2)< md_sensors(2)-100|| mcp_f(3)< md_sensors(3)-100)
            {
              break;
            }
      }
    Motor(0, 0, 0, 0);delay(100);
  }

void robot_TR(int sp, int offset)
  {
    /*
    while(1)
      {
        Motor(sp/1.5, sp/1.5, sp/1.5, sp/1.5);
        if(mcp_f(2)> md_sensors(2)&& mcp_f(3)> md_sensors(3))
            {
              break;
            }
      }
    */
    Motor(0, 0, 0, 0);delay(100);
    do{Motor(sp, -sp, sp, -sp);}while(mcp_f(1)< md_sensors(1));delay(100);
    do{Motor(sp, -sp, sp, -sp);}while(mcp_f(1)> md_sensors(1));
    do{Motor(sp, -sp, sp, -sp);}while(mcp_f(0)> md_sensors(0));
    Motor(-sp, sp, -sp, sp);delay(offset);
    Motor(0, 0, 0, 0);delay(100);
  }
  
void robot_TL(int sp, int offset)
  {
    /*
    while(1)
      {
        Motor(sp/1.5, sp/1.5, sp/1.5, sp/1.5);
        if(mcp_f(2)> md_sensors(2)&& mcp_f(3)> md_sensors(3))
            {
              break;
            }
      }
    */
    Motor(0, 0, 0, 0);delay(100);
    do{Motor(-sp, sp, -sp, sp);}while(mcp_f(0)< md_sensors(0));delay(100);
    do{Motor(-sp, sp, -sp, sp);}while(mcp_f(0)> md_sensors(0));
    do{Motor(-sp, sp, -sp, sp);}while(mcp_f(1)> md_sensors(1));
    Motor(sp, -sp, sp, -sp);delay(offset);
    Motor(0, 0, 0, 0);delay(100);
  }
