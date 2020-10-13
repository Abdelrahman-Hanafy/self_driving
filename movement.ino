void Backward(int lspeed)
{
  analogWrite(ForwardRight, 0);
  analogWrite(ForwardLeft, lspeed);
  analogWrite(BackwardRight, lspeed);
  analogWrite(BackwardLeft, 0);
}

void Forward(int lspeed)
{
  analogWrite(ForwardRight, lspeed);
  analogWrite(ForwardLeft, 0);
  analogWrite(BackwardRight, 0);
  analogWrite(BackwardLeft, lspeed);
}

void MoveLeft(int rspeed)
{
  analogWrite(ForwardRight, rspeed);
  analogWrite(ForwardLeft, rspeed);
  analogWrite(BackwardRight, 0);
  analogWrite(BackwardLeft, 0);
}

void MoveRight(int rspeed)
{
  analogWrite(ForwardRight, 0);
  analogWrite(ForwardLeft, 0);
  analogWrite(BackwardRight, rspeed);
  analogWrite(BackwardLeft, rspeed);
}

void Stand()
{
  analogWrite(ForwardRight, 0);
  analogWrite(ForwardLeft, 0);
  analogWrite(BackwardRight, 0);
  analogWrite(BackwardLeft, 0);
}

void ManoeuvreL(){
flag=true;
  cdeg = compass();
  if (cdeg < 270){gdeg = cdeg+90;}
  else if (cdeg >= 270) { gdeg = cdeg-270;}
  Serial.println(gdeg);
  //delay(1000);
  while(flag){
    MoveLeft(100);
    cdeg = compass();
    if((cdeg > gdeg) && (gdeg > 90)){
      flag = false;
     
      }else if ((cdeg < gdeg) && (gdeg < 90)){
        flag=false;
        }    
    }
    
  }

void ManoeuvreR(){
flag=true;
  cdeg = compass();
  if (cdeg < 90){gdeg = 270+cdeg;}
  else if (cdeg >= 90) { gdeg = cdeg-90;}
  Serial.println(gdeg);
  //delay(1000);
  while(flag){
    MoveRight(100);
    cdeg = compass();
    if((cdeg > gdeg) && (gdeg > 270)){
      flag = false;
     
      }else if ((cdeg < gdeg) && (gdeg < 270)){
        flag=false;
        }    
    }
  }

bool flagx=true, flagy=true;
void driveto(float glat, float glon){
  
Serial.print("drive to "); Serial.println(glon);

while(Lon!=glon){
  timer = millis();

if (glon > Lon){
  Forward(60);
}
else if (glon < Lon )
{
  if (flagx){
    ManoeuvreL();
    flagx=false;
  }
  Forward(60);
}
GPS(); 
}
  Stand();
    Serial.println("Waaah"); 
}
