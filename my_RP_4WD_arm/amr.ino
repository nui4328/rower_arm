void co_xyz( float co_y, float co_z, int sp) 
  {  
    float co_x=0; 
    const float L1sq = sq(ROBOT_ARM_LOW);
    const float L2sq = sq(ROBOT_ARM_HIGH);
    float rrot_ee = hypot(co_x, co_y);
    float rrot =  rrot_ee - ROBOT_ARM_EE_OFFSET;
    float rside = hypot(rrot, co_z);
    float RSsq = sq(rside);
  
    rot = acos(co_x/ rrot_ee);  
    high = PI - acos((L1sq + L2sq - RSsq) / (2 * ROBOT_ARM_LOW * ROBOT_ARM_HIGH));    
    if (co_z > 0) 
      {
        low =  acos(co_z / rside) - acos((L1sq - L2sq + RSsq) / (2 * ROBOT_ARM_LOW * rside));
      } 
    else 
      {
        low = PI - asin(rrot / rside) - acos((L1sq - L2sq + RSsq) / (2 * ROBOT_ARM_LOW * rside));
      }
  
    high = high + low;
   // Serial.print(degrees(rot));
   // Serial.print(" ");
    //Serial.print(90+degrees(low));
    //Serial.print(" ");
   //Serial.println(180-degrees(high));
    theta2 = 90+degrees(low);
    theta3 = (180-degrees(high))-10;

    Serial.print(degrees(rot));
    Serial.print(" ");
    Serial.print(theta2);
    Serial.print(" ");
    Serial.println(theta3);
    //servo(23, theta2);
    //servo(22, theta3);
    
    
     float servo23_step = (theta2 - s23_before_deg) / num_steps;
     float servo22_step = (theta3 - s22_before_deg) / num_steps;
     Serial.print(" ");
     Serial.print(servo23_step);
     Serial.print(" ");
     Serial.println(servo22_step);
      for (int i = 0; i < num_steps; i++) 
        {
          float servo23_pos = s23_before_deg + (i * servo23_step);
          float servo22_pos = s22_before_deg + (i * servo22_step);
          servo(23, servo23_pos);
          servo(22, servo22_pos);
          
          delay(sp);
        }
     s23_before_deg = theta2;
     s22_before_deg = theta3;
  }
void co_xyz(float co_x, float co_y, float co_z, int sp) 
  {  
    const float L1sq = sq(ROBOT_ARM_LOW);
    const float L2sq = sq(ROBOT_ARM_HIGH);
    float rrot_ee = hypot(co_x, co_y);
    float rrot =  rrot_ee - ROBOT_ARM_EE_OFFSET;
    float rside = hypot(rrot, co_z);
    float RSsq = sq(rside);
  
    rot = acos(co_x/ rrot_ee);  
    high = PI - acos((L1sq + L2sq - RSsq) / (2 * ROBOT_ARM_LOW * ROBOT_ARM_HIGH));    
    if (co_z > 0) 
      {
        low =  acos(co_z / rside) - acos((L1sq - L2sq + RSsq) / (2 * ROBOT_ARM_LOW * rside));
      } 
    else 
      {
        low = PI - asin(rrot / rside) - acos((L1sq - L2sq + RSsq) / (2 * ROBOT_ARM_LOW * rside));
      }
  
    high = high + low;
   // Serial.print(degrees(rot));
   // Serial.print(" ");
    //Serial.print(90+degrees(low));
    //Serial.print(" ");
   //Serial.println(180-degrees(high));
    theta1 = 90-degrees(rot);
    theta2 = 90+degrees(low);
    theta3 = (180-degrees(high))-10;

    
    //servo(23, theta2);
    //servo(22, theta3);
    
     float servo28_step = (theta1 - s28_before_deg) / num_steps;
     float servo23_step = (theta2 - s23_before_deg) / num_steps;
     float servo22_step = (theta3 - s22_before_deg) / num_steps;
     //Serial.print(" ");
     //Serial.print(servo23_step);
     //Serial.print(" ");
     //Serial.println(servo22_step);
     //do{Motor(50, -50, 50, -50);}while(error_Yaw_float() < theta1);
     Motor(0, 0, 0, 0);
     
      for (int i = 0; i < num_steps; i++) 
        {
          float servo28_pos = s28_before_deg + (i * servo28_step);
          float servo23_pos = s23_before_deg + (i * servo23_step);
          float servo22_pos = s22_before_deg + (i * servo22_step);
          servo(23, servo23_pos);
          servo(22, servo22_pos);
          //Serial.println(servo28_pos);
         
          if(theta1>1)
            {
              do{Motor(50, -50, 50, -50);}while(error_Yaw_float()< servo28_pos);
              ch_x = 1;              
            } 
         else if(theta1<-1)
            {
              do{Motor(-50, 50, -50, 50);}while(error_Yaw_float()> servo28_pos);
              ch_x = 0;
            } 
         else
            {
              if(ch_x == 0)
                {
                  do{Motor(50, -50, 50, -50);}while(error_Yaw_float()< servo28_pos);                  
                }
              else
                {
                  do{Motor(-50, 50, -50, 50);}while(error_Yaw_float()> servo28_pos);
                  
                }              
            }
          Motor(0, 0, 0, 0);
          delay(sp);
        }
    
     s28_before_deg = theta1;
     s23_before_deg = theta2;
     s22_before_deg = theta3;
     Motor(0, 0, 0, 0);
    Serial.print(theta1);
    Serial.print("   ");
    Serial.print(theta2);
    Serial.print("   ");
    Serial.println(theta3);

  }
