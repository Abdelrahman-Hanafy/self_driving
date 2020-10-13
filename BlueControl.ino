
//reading from bluetooth
String com = "" ;
char state; 
float glat=0, glon=0;
int lspeed = 125, rspeed = 125;

void Blisten(){
  if (Serial.available() > 0) { // Checks whether data is comming from the serial port
    state = Serial.read(); // Reads the data from the serial port

  switch(state){
    
    case 'F': Forward(lspeed);break;
    case 'B': Backward(lspeed);break;
    case 'R': MoveRight(rspeed);break;
    case 'L': MoveLeft(rspeed);break;
    case 'S': Stand();break;

    case 'I': lspeed+=5;break;
    case 'i': lspeed-=5;break;
    case 'W': rspeed+=5;break;
    case 'w': rspeed-=5;break;

    case 'M': ManoeuvreL();break;
    case 'm': ManoeuvreR();break;
    
    case 'b': ManoeuvreL();ManoeuvreL();break;
    case 'V': avoid();break;

    case 'A': Serial.println(compass());break;
    case 'P': Serial.print("Pose: "); Serial.print(Lon); Serial.print(" : "); Serial.println(Lat);break;  

    case 'G': driveto(glat,glon);break;
    
    default: if (state == 'e'){
          parsecom(com);
          com="";  
          }else{
          com += state;
          }     
    }
//      if (state == 'F') 
//    {
//      //avoid(lspeed,rspeed);
//      Forward(lspeed);
//    }
//    else if (state == 'B')
//    {
//      Backward(lspeed);
//    }
//    else if (state == 'R')
//    {
//      MoveRight(rspeed);
//    }
//    else if (state == 'L')
//    {
//      MoveLeft(rspeed);
//    }
//    else if (state == 'S')
//    {
//      Stand();
//    }
//    else if (state == 'I')
//    {
//      lspeed+=5;
//    } 
//    else if (state == 'D')
//    {
//      lspeed-=5;
//    }
//    else if (state == 'W')
//    {
//      rspeed+=5;
//    }
//    else if (state == 'w')
//    {
//      rspeed-=5;
//    }
//    else if (state == 'G')
//    {
//      driveto(glat,glon);
//    }
//    else if (state == 'M')
//    {
//      ManoeuvreL();
//    }
//      else if (state == 'm')
//    {
//      ManoeuvreR();
//    }
//    else if (state == 'A')
//    {
//      Serial.println(compass());
//    }
//    else if (state == 'P')
//    {
//      Serial.print("Pose: "); Serial.print(Lon); Serial.print(" : "); Serial.println(Lat);
//    }
//    else if (state == 'V')
//    {
//      avoid();
//    }
//    else
//    {
//      //Serial.println("start collicting string");
//        //Serial.println(state);
//        if (state == 'e'){
//          parsecom(com);
//          com="";  
//          }else{
//          com += state;
//          }     
//    }
  }
}

void parsecom(String com){
  
  String pose, Value;
    
  pose = com.substring(0,com.indexOf(":"));
  Value = com.substring(com.indexOf(":")+1);

  char buf[Value.length()+1];
  Value.toCharArray(buf,Value.length()+1); 

//Serial.print("parsing: ");Serial.println(com);
//Serial.print("pose: ");Serial.println(pose);
//Serial.print("value: ");Serial.println(buf);

  if(pose.equalsIgnoreCase("lat")){
    glat =  atof(buf);
    }
  else if(pose.equalsIgnoreCase("lon")){
    glon = atof(buf);
    }
  }
