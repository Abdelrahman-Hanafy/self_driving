
int compass(){
 
   if(mag.begin())
  {
 
  sensors_event_t event; 
  mag.getEvent(&event);
 
  float heading = atan2(event.magnetic.y, event.magnetic.x);
  
  float declinationAngle = 0.05;
  heading += declinationAngle;
  
  // Correct for when signs are reversed.
  if(heading < 0)
    heading += 2*PI;
    
  // Check for wrap due to addition of declination.
  if(heading > 2*PI)
    heading -= 2*PI;
   
  // Convert radians to degrees for readability.
  float headingDegrees = heading * 180/M_PI; 

  return (int)headingDegrees;
  }else{
    Serial.print("Failed");
    return 500;
    }

}
