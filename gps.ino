//int Data;
void GPS(){
  
//  if (Serial1.available() > 0) { // Checks whether data is comming from the serial port
//    Data = Serial1.read(); // Reads the data from the serial port
//  //Serial.println("REading");
//  if(gps.encode(Data)){
//    Serial.println(Data);
//    Lat = gps.location.lat();
//    Lon = gps.location.lng();
//    }
//  
//  }

if(timer-pre >= 500){
  pre = timer;
  
  if (Lon <= glon){Update();}
  else if (Lon > glon){Decrt();}
  
  Serial.print("Driving from: "); Serial.println(Lon);
  }  
}

void Update(){
  Lon += 0.2;
  }
  
void Decrt(){
  Lon -= 0.2;
  }
