
// defines variables
long duration;
int distance;
int forw, left, right; 
int gdeg, cdeg;
bool flag=true;

int see(){

    servo.write(115);
    
// Clears the trigPin
digitalWrite(trig, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trig, HIGH);
delayMicroseconds(10);
digitalWrite(trig, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echo, HIGH);

// Calculating the distance
distance= duration*0.034/2;

return distance;
}

int seel(){

  servo.write(170);
    delay(500);

  
// Clears the trigPin
digitalWrite(trig, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trig, HIGH);
delayMicroseconds(10);
digitalWrite(trig, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echo, HIGH);

// Calculating the distance
distance= duration*0.034/2;

  servo.write(115);

return distance;
}

int seer(){

  servo.write(50);
    delay(500);

  
// Clears the trigPin
digitalWrite(trig, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trig, HIGH);
delayMicroseconds(10);
digitalWrite(trig, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echo, HIGH);

// Calculating the distance
distance= duration*0.034/2;

  servo.write(115);

return distance;
}


void avoid(){
  
  forw = see();

  if(forw > 20){
    
    Forward(lspeed);
    //Serial.println("forward");
    }
  
  else{

    Backward(100);
    delay(200);
    Stand();
    
    left = seel();
    right = seer();

    // trurn around the obstical
    if (left > right){
          //Serial.print("Avoid left");
    	ManoeuvreL();
        Forward(100);
        delay(500);
    	ManoeuvreR();
        
    		}
       
	  else if (left <= right){
         // Serial.println("Avoid right");
      	ManoeuvreR();
        Forward(100);
        delay(500);
        ManoeuvreL();
        }
    
    }
  
}
