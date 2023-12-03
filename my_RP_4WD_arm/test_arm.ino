void co_a( float co_x, float co_y, float co_z) 
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

    Serial.println(rrot_ee);
  }
