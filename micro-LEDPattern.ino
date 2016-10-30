byte red=9;              // output pin red
byte green=10;          // output pin green
byte blue=11;          // output pin blue
byte led[8]={1,2,3,4,5,6,7,8};      // pins for LEDs
byte var=0;
byte light_speed=10;                 //smallest is faster
const byte width=60;               //width of the display metrix

byte disp [width][8][3]= {0};      //display metrix
byte counter=0;
void setup() {                     // pin setup
  
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  counter=0;
  
}

void loop() {
//lightL(255,0,0,0,0,0);

  
  var=rand()%4;                                    //random number for switch patterns randomly
  
  if(var==0){
       
        byte rand_var=rand()%6;                     //random number for switch background and forground colors randomly
        
        if(rand_var==0){
          for(int i=0;i<6;i++)
          lightKnightRider(255,0,0,0,255,0);
        }
        else if(rand_var==1){
          for(int i=0;i<6;i++)
          lightKnightRider(255,0,0,0,0,255);
        }
        else if(rand_var==2){
          for(int i=0;i<6;i++)
          lightKnightRider(0,255,0,0,0,255);
        }
        else if(rand_var==3){
          for(int i=0;i<6;i++)
          lightKnightRider(0,255,0,255,0,0);
        }
        else if(rand_var==4){
          for(int i=0;i<6;i++)
          lightKnightRider(0,0,255,255,0,0);
        }
        else if(rand_var==5){
          for(int i=0;i<6;i++)
          lightKnightRider(0,0,255,0,255,0);
        }
  }
  else if(var==1){
    
        byte rand_var=rand()%6; 
        
        if(rand_var==0){
          for(int i=0;i<10;i++)
          lightPattern2(255,0,0,0,255,0);
        }
        else if(rand_var==1){
          for(int i=0;i<10;i++)
          lightPattern2(255,0,0,0,0,255);
        }
        else if(rand_var==2){
          for(int i=0;i<10;i++)
          lightPattern2(0,255,0,0,0,255);
        }
        else if(rand_var==3){
          for(int i=0;i<10;i++)
          lightPattern2(0,255,0,255,0,0);
        }
        else if(rand_var==4){
          for(int i=0;i<10;i++)
          lightPattern2(0,0,255,255,0,0);
        }
        else if(rand_var==5){
          for(int i=0;i<10;i++)
          lightPattern2(0,0,255,0,255,0);
        }
  }
    else if(var==2){
      
         byte rand_var=rand()%6; 
        
        if(rand_var==0){
          for(int i=0;i<6;i++)
          lightPattern3(255,0,0,0,255,0);
        }
        else if(rand_var==1){
          for(int i=0;i<6;i++)
          lightPattern3(255,0,0,0,0,255);
        }
        else if(rand_var==2){
          for(int i=0;i<6;i++)
          lightPattern3(0,255,0,0,0,255);
        }
        else if(rand_var==3){
          for(int i=0;i<6;i++)
          lightPattern3(0,255,0,255,0,0);
        }
        else if(rand_var==4){
          for(int i=0;i<6;i++)
          lightPattern3(0,0,255,255,0,0);
        }
        else if(rand_var==5){
          for(int i=0;i<6;i++)
          lightPattern3(0,0,255,0,255,0);
        }
  }
  else {
  
        for(int i=0;i<30;i++)
        lightPattern1();
  }

}
/*  pattern 1 */

// r g g b b r r g
// r r g g b b r r
// b r r g g b b r
// b b r r g g b b
// g b b r r g g b
// g g b b r r g g

void lightPattern1(){ 
  setupPattern1();
  
  counter=0;
  while(counter!=6){
    for(int t=0;t<=light_speed  ;t++)
    lightUpLine(counter);
    counter++;
  }
}



/*  pattern 2 */
// ________
// ___00___
// __0000__
// _000000_
// 00000000
// _000000_
// __0000__
// ___00___

void lightPattern2(int fr,int fg, int fb, int br,int bg,int bb){ 
  setupPattern2(fr,fg,fb,br,bg,bb);
  
  counter=0;
  while(counter!=8){
    for(int t=0;t<=light_speed  ;t++)
    lightUpLine(counter);
    counter++;
  }
}

/*  pattern 3 */
// ________
// 0_______
// 00______
// 000_____
// 0000____
// 00000___
// 000000__
// 0000000_
// 00000000
// 0000000_
// 000000__
// 00000___
// 000_____
// 00______
// 0_______

void lightPattern3(int fr,int fg, int fb, int br,int bg,int bb){ 
  setupPattern3(fr,fg,fb,br,bg,bb);
  
  counter=0;
  while(counter!=16){
    for(int t=0;t<=light_speed  ;t++)
    lightUpLine(counter);
    counter++;
  }
}


void lightL(int fr,int fg, int fb, int br,int bg,int bb){ 
  setupL(fr,fg,fb,br,bg,bb);
  
  counter=0;
  while(counter!=60){
    for(int t=0;t<=light_speed  ;t++)
    lightUpLine(counter);
    counter++;
  }
}
/* knight rider*/
// ________
// 0_______
// 00______
// 000_____
// _000____
// __000___
// ___000__
// ____000_
// _____000
// ______00
// _______0

void lightKnightRider(int fr,int fg, int fb, int br,int bg,int bb){ // setup and light  knight rider pattern with given forground and background colors
  
  setupKnightRider(fr,fg,fb,br,bg,bb);
  
  counter=0;
  while(counter!=18){
    for(int t=0;t<=light_speed  ;t++)
    lightUpLine(counter);
    counter++;
  }
  
}



void setupPattern1(){
  for(byte x=0;x<6;x++){
      for(byte y=0;y<=7;y++){
        if((x+y)%6==0)
          lightLED(x,y,255,0,0);  
        else if((x+y)%6==1)
          lightLED(x,y,0,255,0);  
        else if((x+y)%6==2)
          lightLED(x,y,0,255,0); 
        else if((x+y)%6==3)
          lightLED(x,y,0,0,255); 
        else if((x+y)%6==4)
          lightLED(x,y,0,0,255); 
        else if((x+y)%6==5)
          lightLED(x,y,255,0,0);           
      }
      
  }
  
}


void setupPattern2(int fr,int fg, int fb, int br,int bg,int bb){
  for(byte x=0;x<8;x++){
    byte temp=abs(x-4);
      for(byte y=0;y<=3;y++){
               if(y>=temp){
                  lightLED(x,y,fr,fg,fb);
                  lightLED(x,7-y,fr,fg,fb);
               }
                else{
                  lightLED(x,y,br,bg,bb);
                  lightLED(x,7-y,br,bg,bb);
                }   
      }
      
  }
  
}

void setupL(int fr,int fg, int fb, int br,int bg,int bb){
  for(byte x=0;x<8;x++){
    for(byte y=0; y<8;y++){
      if(x>=1 && y>=2){
        lightLED(x,y,0,0,0);
      }
      else
       lightLED(x,y,fr,fg,fb); 
}
  }
  
  
  for(byte x=12;x<60;x++){
    for(byte y=0; y<8;y++){
      lightLED(x,y,0,0,0);
    }
  }
  
}
  
void setupPattern3(int fr,int fg, int fb, int br,int bg,int bb){
  for(byte x=0;x<16;x++){
    byte temp=abs(x-8);
      for(byte y=0;y<=7;y++){
               if(y>=temp){
                  lightLED(x,y,fr,fg,fb);
               }
                else{
                  lightLED(x,y,br,bg,bb);
                }   
      }
      
  }
  
}


void setupKnightRider(int fr,int fg, int fb, int br,int bg,int bb){      // set rgb values to the diplay metrix in order to create knight rider pattern with given forground and background colors
  int i=-2;
  boolean up=true;
  for(byte x=0;x<18;x++){
      for(byte y=0;y<=7;y++){
        lightLED(x,y,br,bg,bb);        
           if(y==i)
            lightLED(x,y,fr,fg,fb);
          else if(y==(i+1))
            lightLED(x,y,fr,fg,fb);
           else if(y==(i+2))
            lightLED(x,y,fr,fg,fb); 
      }
            
          if(up)
          i++;
          else
          i--;
          
          if(i==7){
            up=false;
          }else if(i==-2)
          {
            up=true;
          }
    }
}



void lightUpLine(byte n){      //light up line n of the display
  for(byte i=0;i<8;i++){        //multiplexing 8 LEDs

    analogWrite(red,disp[n][i][0]);
    analogWrite(green,disp[n][i][1]);
    analogWrite(blue,disp[n][i][2]);
    
    digitalWrite(led[i],HIGH);
    //delay(1);
    digitalWrite(led[i],LOW);
    
  }
}

void lightLED(byte x,byte y,byte r,byte g, byte b){  //set rgb values of a LED
  disp[x][y][0]=255-r;                               //255 need to be subtracted from each value since these are common anode LEDs
  disp[x][y][1]=255-g;
  disp[x][y][2]=255-b;
}
