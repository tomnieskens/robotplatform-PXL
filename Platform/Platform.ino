#include <Wire.h>

#define MD03_1    0x58
#define MD03_2    0x59
#define CMD_reg   0x00
#define SPEED_reg 0x02
#define ACC_reg   0x03 
 
 int valueFB = 500; //variable value forward backward
 int valueLR = 500; //variable value left right
 
 
 

 unsigned long speed1;
 unsigned long speed2;
 int speed;
 int recievedChar = 0;


void setup()
{
  Serial.begin(115200);// begin the serial communicaton


  

  {
  Wire.begin(); // join i2c bus (address optional for master)

  
}

}





void loop()
{  

  recievedChar =Serial.parseInt();
  if (recievedChar > 0)
  {
   if(recievedChar==1066){// if it sees 1066 then it knows that valueFB is comming
   valueFB = Serial.parseInt();  //Reads integers as integer rather than ASCI. Anything else returns 0
   Serial.println(valueFB);// prints valueFB so I could see it int the serial monitor
  
   }
   if(recievedChar==1065){// if it sees 1066 then it knows that valueLR is comming
   valueLR = Serial.parseInt();  //Reads integers as integer rather than ASCI. Anything else returns 0
   Serial.println(valueLR);// prints valueLR so I could see it int the serial monitor
 
   }
  }else{
  valueLR = 500;
  valueFB = 500;
  }

 

  

 if(valueFB>510){                                                           //forwards
      if(valueLR>505){                                                       //forwards+left
      speed1 =((valueFB-400)/2);
      speed2 =((valueFB-400)/2)-((valueLR-450)/2) ;       // left motor slows down
      }
      else if(valueLR<495){                                               //forwards+right
      speed1 = ((valueFB-400)/2)-((550-valueLR)/2);      // right motor slows down
      speed2 =((valueFB-400)/2) ;
      }
      else{                                                                        //forwards
      speed1 = ((valueFB-400)/2);
      speed2 = ((valueFB-400)/2);
      }                                                   
    Wire.beginTransmission(MD03_1); 
    Wire.write(SPEED_reg);          
    Wire.write(speed1);              
    Wire.endTransmission();
    Wire.beginTransmission(MD03_2); 
    Wire.write(SPEED_reg);          
    Wire.write(speed2);           
    Wire.endTransmission();

    Wire.beginTransmission(MD03_1); 
    Wire.write(ACC_reg);         
    Wire.write(27);             
    Wire.endTransmission();
    Wire.beginTransmission(MD03_2); 
    Wire.write(ACC_reg);         
    Wire.write(27);             
    Wire.endTransmission();
    Wire.beginTransmission(MD03_1); 
    Wire.write(CMD_reg);        
    Wire.write(1);              // sets motor forwards
    Wire.endTransmission();    
    Wire.beginTransmission(MD03_2); 
    Wire.write(CMD_reg);        
    Wire.write(1);              // sets motor forwards
    Wire.endTransmission(); 
  
  
  
  }
  else if(valueFB<490){                                                   //backwards
       if(valueLR>505){                                                    //backwards+left
      speed1 =((600-valueFB)/2);
      speed2 =((600-valueFB)/2)-((valueLR-450)/2);      // left motor slows down 
      }
      else if(valueLR<495){                                             //backwards+right
      speed1 =((600-valueFB)/2)-((550-valueLR)/2);      // right motor slows down
      speed2 =((600-valueFB)/2);
      }
      else{                                                                       //backwards
      speed1 =((600-valueFB)/2);
      speed2 =((600-valueFB)/2);
      }   
    Wire.beginTransmission(MD03_1); 
    Wire.write(SPEED_reg);          
    Wire.write(speed1);              
    Wire.endTransmission();
    Wire.beginTransmission(MD03_2); 
    Wire.write(SPEED_reg);          
    Wire.write(speed2);           
    Wire.endTransmission();

    Wire.beginTransmission(MD03_1); 
    Wire.write(ACC_reg);         
    Wire.write(27);             
    Wire.endTransmission();
    Wire.beginTransmission(MD03_2); 
    Wire.write(ACC_reg);         
    Wire.write(27);             
    Wire.endTransmission();
    Wire.beginTransmission(MD03_1); 
    Wire.write(CMD_reg);        
    Wire.write(2);              // sets motor backwords
    Wire.endTransmission();    
    Wire.beginTransmission(MD03_2); 
    Wire.write(CMD_reg);        
    Wire.write(2);              // sets motor backwords
    Wire.endTransmission(); 
  
  }
  else if (valueFB>490 and valueFB<510){                                  //left and right
      if(valueLR>505){                                                                  //left
    speed1 =((valueLR-400)/2);
    
    Wire.beginTransmission(MD03_1); 
    Wire.write(SPEED_reg);          
    Wire.write(speed1);              
    Wire.endTransmission();
    Wire.beginTransmission(MD03_2); 
    Wire.write(SPEED_reg);          
    Wire.write(speed1);           
    Wire.endTransmission();

    Wire.beginTransmission(MD03_1); 
    Wire.write(ACC_reg);         
    Wire.write(27);             
    Wire.endTransmission();
    Wire.beginTransmission(MD03_2); 
    Wire.write(ACC_reg);         
    Wire.write(27);             
    Wire.endTransmission();
    Wire.beginTransmission(MD03_1); 
    Wire.write(CMD_reg);        
    Wire.write(1);              // sets motor forwards
    Wire.endTransmission();    
    Wire.beginTransmission(MD03_2); 
    Wire.write(CMD_reg);        
    Wire.write(2);              // sets motor backwards
    Wire.endTransmission(); 
  
      }
      else if(valueLR<495){                                                            //right
    speed1 =((600-valueLR)/2);
    
    Wire.beginTransmission(MD03_1); 
    Wire.write(SPEED_reg);          
    Wire.write(speed1);              
    Wire.endTransmission();
    Wire.beginTransmission(MD03_2); 
    Wire.write(SPEED_reg);          
    Wire.write(speed1);           
    Wire.endTransmission();

    Wire.beginTransmission(MD03_1); 
    Wire.write(ACC_reg);         
    Wire.write(27);             
    Wire.endTransmission();
    Wire.beginTransmission(MD03_2); 
    Wire.write(ACC_reg);         
    Wire.write(27);             
    Wire.endTransmission();
    Wire.beginTransmission(MD03_1); 
    Wire.write(CMD_reg);        
    Wire.write(2);              // sets motor backwards
    Wire.endTransmission();    
    Wire.beginTransmission(MD03_2); 
    Wire.write(CMD_reg);        
    Wire.write(1);              // sets motor forwards
    Wire.endTransmission(); 
  
      }
      else{                                                                                    //stops
      
      
    Wire.beginTransmission(MD03_1); 
    Wire.write(SPEED_reg);          
    Wire.write(0);              
    Wire.endTransmission();
    Wire.beginTransmission(MD03_2); 
    Wire.write(SPEED_reg);          
    Wire.write(0);           
    Wire.endTransmission();

    Wire.beginTransmission(MD03_1); 
    Wire.write(ACC_reg);         
    Wire.write(27);             
    Wire.endTransmission();
    Wire.beginTransmission(MD03_2); 
    Wire.write(ACC_reg);         
    Wire.write(27);             
    Wire.endTransmission();
    Wire.beginTransmission(MD03_1); 
    Wire.write(CMD_reg);        
    Wire.write(0);              // stops motor 
    Wire.endTransmission();    
    Wire.beginTransmission(MD03_2); 
    Wire.write(CMD_reg);        
    Wire.write(0);              // stops motor
    Wire.endTransmission(); 
  
      }
  }
}  
