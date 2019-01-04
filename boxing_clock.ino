
 #include <FastLED.h> 
                
#define NUM_Disp 7                      /*Defining number of displays*/
#define NUM_Led 112                     
#define WorkMode 36                     /*Deffining inputs*/
#define IntervalMode 25
#define DecreaseSeconds 39
#define IncreaseSeconds 4
#define DecreaseMinutes 21
#define IncreaseMinutes 34
#define IncreaseInterval 35
#define DecreaseInterval 32
#define Bell 23                                                            /*Global variables*/
CRGB LedsOnDisplay[NUM_Disp][NUM_Led];

byte DefinedWorkingMinutes=3;
byte DefinedWorkingSeconds=0;
byte DefinedRestingMinutes=1;
byte DefinedRestingSeconds=0;
int RoundTotal=1;
int WorkingMinutes=3;
int WorkingSeconds=0;
int RestingMinutes=1;
int RestingSeconds=0;
int IntervalPeriod=20;
int IntervalCountDown=20;
bool SetWorkTime=true;
bool SetRestTime=false;
bool WorkTime=true;
bool RestTime=false;


int SecondsCounter;
byte DisplayNUM;
byte SecondsOnes=0;
byte SecondsTens=0;
byte h=0;
byte s=255;
byte v=255;
byte Disp;
unsigned long CurrentTime;
unsigned long SetWorkTimeMark;
unsigned long CountDown;
unsigned long SetupTimeMark;
 
void ClearDisp1();void ClearDisp2();void ClearDisp3();void ClearDisp4();void ClearDisp5();void ClearDisp6();
void ClearUserInterface();
void ClearIntervalDisplay();
void PlusDisplay();
void MinusDisplay();
void DotsDisplay();
void IntervalDisplay();
void WorkDisplay();
void SetupDisplay();
 void N0();void N1();void N2();void N3();void N4();void N5();void N6();void N7();void N8();void N9();
void Minutes(int Min);
void Seconds (int Sec);
void Interval(int Int);
void Rounds(int Rnd);

void setup() {

                                                                                                     /*Setting up inputs*/
 pinMode(WorkMode,INPUT);    pinMode(IntervalMode,INPUT);    pinMode(DecreaseSeconds,INPUT);  
  pinMode(IncreaseSeconds,INPUT); pinMode(DecreaseMinutes,INPUT);pinMode(IncreaseMinutes,INPUT);
  pinMode(IncreaseInterval,INPUT);pinMode(DecreaseInterval,INPUT);
       
                                                                                                     /*Setting  up outputs*/
FastLED.addLeds<WS2812, 18, GRB>(LedsOnDisplay[0], NUM_Led); 
 FastLED.addLeds<WS2812, 17, GRB>(LedsOnDisplay[1], NUM_Led); 
  FastLED.addLeds<WS2812, 16, GRB>(LedsOnDisplay[2], NUM_Led); 
  FastLED.addLeds<WS2812, 15, GRB>(LedsOnDisplay[3], NUM_Led);
  FastLED.addLeds<WS2812, 14, GRB>(LedsOnDisplay[4], NUM_Led); 
    FastLED.addLeds<WS2812, 13, GRB>(LedsOnDisplay[5], NUM_Led); 
    FastLED.addLeds<WS2812, 12, GRB>(LedsOnDisplay[6], NUM_Led); 
pinMode(Bell,OUTPUT);


constrain(RoundTotal,0,99);
  
 Serial.begin(9600); // put your setup code here, to run once:

}




void loop() {
  for(byte i=0;i<7;i++){                                                                         /*startup animation*/
   
   if(DisplayNUM==0){for (byte i=0; i < NUM_Led;i++){
  LedsOnDisplay[DisplayNUM][i] = CHSV(h, s, v);
  h=random(20,50);
 s=random(240,255);v=v-10;
  FastLED.show();
  }
   for (byte i=0; i < NUM_Led;i++){
     LedsOnDisplay[DisplayNUM][i] = CHSV(h, s, v);
  h=random(0,20);v=v+13;
s=random(240,255);
  FastLED.show();}
     for (byte i=0; i < NUM_Led;i++){
     LedsOnDisplay[DisplayNUM][i] = CHSV(h, s, v);
  h=random(5,160);v=v+13;
s=random(240,255);
  FastLED.show();}}
else{for (byte i=0; i < 56;i++){
  LedsOnDisplay[DisplayNUM][i] = CHSV(h, s, v);
  h=random(0,10);
 s=random(240,255);v=random(0,255);
  FastLED.show();
  }
   for (byte i=0; i < 56;i++){
     LedsOnDisplay[DisplayNUM][i] = CHSV(h, s, v);
 h=random(50,160);v=random(0,255);
s=random(200,255);
  FastLED.show();}}
  
DisplayNUM++;
if(DisplayNUM==7){DisplayNUM=0;}}




bool ShowAnimation=true;
CurrentTime=millis();
 WorkingMinutes=DefinedWorkingMinutes;
 WorkingSeconds=DefinedWorkingSeconds;
 RestingMinutes=DefinedRestingMinutes;
 RestingSeconds=DefinedRestingSeconds;
 RoundTotal=1; 
while(digitalRead(WorkMode)==LOW && digitalRead(IntervalMode)==LOW){                                                 /*setup mode*/
   if(ShowAnimation==true){ClearUserInterface(); h=random(90,110);s=255;v=190;byte i;
    for(i = 58; i<74;i++){ 
    h=h+3;s=s-2; 
    LedsOnDisplay[0][i]=CHSV(h,s,v);FastLED.show();delay(10);} 
    if(i==74){ShowAnimation=0;}  PlusDisplay();MinusDisplay();h=20;s=240;v=255; DotsDisplay();Serial.println("SetupMode!"); Minutes(DefinedWorkingMinutes);Seconds(DefinedWorkingSeconds);h=75;Interval(IntervalPeriod);}
 SetupTimeMark=millis();
if(SetupTimeMark-CurrentTime>5000){
  if(SetWorkTime==true){SetWorkTime=false;SetRestTime=true;CurrentTime=millis(); h=140;s=240;v=255;Minutes(DefinedRestingMinutes);Seconds(DefinedRestingSeconds);DotsDisplay();}
  else{SetWorkTime=true;SetRestTime=false;CurrentTime=millis();  h=20;s=240;v=255;Minutes(DefinedWorkingMinutes);Seconds(DefinedWorkingSeconds);DotsDisplay();}
  }




if(SetWorkTime==true){
  
    if(digitalRead(IncreaseMinutes)==HIGH){DefinedWorkingMinutes++;if(DefinedWorkingMinutes>59){DefinedWorkingMinutes=59;}  h=20;s=240;v=255; Minutes(DefinedWorkingMinutes);delay(150);CurrentTime=millis();WorkingMinutes=DefinedWorkingMinutes;}
    if(digitalRead(DecreaseMinutes)==HIGH){DefinedWorkingMinutes--; if(DefinedWorkingMinutes<0){DefinedWorkingMinutes=0;}  h=20;s=240;v=255; Minutes(DefinedWorkingMinutes);delay(150);CurrentTime=millis();WorkingMinutes=DefinedWorkingMinutes;}
    if(digitalRead(IncreaseSeconds)==HIGH){DefinedWorkingSeconds++;if(DefinedWorkingSeconds>59){DefinedWorkingSeconds=59;}  h=20;s=240;v=255; Seconds(DefinedWorkingSeconds);delay(150);CurrentTime=millis();WorkingSeconds=DefinedWorkingSeconds;}
    if(digitalRead(DecreaseSeconds)==HIGH){DefinedWorkingSeconds--; if(DefinedWorkingSeconds<0){DefinedWorkingSeconds=0;} h=20;s=240;v=255; Seconds(DefinedWorkingSeconds);delay(150);CurrentTime=millis();WorkingSeconds=DefinedWorkingSeconds;}
    
       if(digitalRead(IncreaseInterval)==HIGH){h=75;s=240;v=255;
      IntervalPeriod +=5;if(IntervalPeriod>60){IntervalPeriod=60;}
    Interval(IntervalPeriod);IntervalDisplay();delay(150);ClearIntervalDisplay();h=75;s=240;v=255;Interval(IntervalPeriod);}
       if(digitalRead(DecreaseInterval)==HIGH){h=75;s=240;v=255;
      IntervalPeriod -=5;
      if(IntervalPeriod<5){IntervalPeriod=5;}
       Interval(IntervalPeriod);IntervalDisplay();delay(150);ClearIntervalDisplay();h=75;s=240;v=255;Interval(IntervalPeriod);}

}

if(SetRestTime==true){
 
    if(digitalRead(IncreaseMinutes)==HIGH){DefinedRestingMinutes++;if(DefinedRestingMinutes>59){DefinedRestingMinutes=59;}  h=140;s=240;v=255; Minutes(DefinedRestingMinutes);delay(150);CurrentTime=millis();RestingMinutes=DefinedRestingMinutes;}
    if(digitalRead(DecreaseMinutes)==HIGH){DefinedRestingMinutes--; if(DefinedRestingMinutes<0){DefinedRestingMinutes=0;}  h=140;s=240;v=255; Minutes(DefinedRestingMinutes);delay(150);CurrentTime=millis();RestingMinutes=DefinedRestingMinutes;}
    if(digitalRead(IncreaseSeconds)==HIGH){DefinedRestingSeconds++;if(DefinedRestingSeconds>59){DefinedRestingSeconds=59;}  h=140;s=240;v=255; Seconds(DefinedRestingSeconds);delay(150);CurrentTime=millis();RestingSeconds=DefinedRestingSeconds;}
    if(digitalRead(DecreaseSeconds)==HIGH){DefinedRestingSeconds--; if(DefinedRestingSeconds<0){DefinedRestingSeconds=0;} h=140;s=240;v=255; Seconds(DefinedRestingSeconds);delay(150);CurrentTime=millis();RestingSeconds=DefinedRestingSeconds;}
  
       if(digitalRead(IncreaseInterval)==HIGH){h=75;s=240;v=255;
      IntervalPeriod +=5;if(IntervalPeriod>60){IntervalPeriod=60;}
    Interval(IntervalPeriod);IntervalDisplay();delay(150);ClearIntervalDisplay();h=75;s=240;v=255;Interval(IntervalPeriod);}
       if(digitalRead(DecreaseInterval)==HIGH){h=75;s=240;v=255;
      IntervalPeriod -=5;
      if(IntervalPeriod<5){IntervalPeriod=5;}
       Interval(IntervalPeriod);IntervalDisplay();delay(150);ClearIntervalDisplay();h=75;s=240;v=255;Interval(IntervalPeriod);}
}
IntervalCountDown=IntervalPeriod;
  }


if(digitalRead(WorkMode)==HIGH){ShowAnimation=true;}                                                                    /*work mode*/
while(digitalRead(WorkMode)==HIGH){
    if(ShowAnimation==true){ClearUserInterface();
    h=random(251,23);s=255;v=255;
  for(byte c = 0; c<40;c++){
    h++;                       
  LedsOnDisplay[0][c]=CHSV(h,s,v);FastLED.show();delay(10);}
      h=random(251,23);s=255;v=255;
  for(byte i = 40; i<58;i++){
    h=h+3;                       
  LedsOnDisplay[0][i]=CHSV(h,s,v);FastLED.show();delay(10);Serial.println(i);
  if(i>=57){ShowAnimation=false;Serial.println("Work mode!");h=WorkingMinutes*5;s=0;v=180;Rounds(RoundTotal);Minutes(WorkingMinutes);Seconds(WorkingSeconds);DotsDisplay();
  delay(2000);digitalWrite(Bell,HIGH);delay(14);digitalWrite(Bell,LOW); }}
}
  CountDown=millis();
  if(CountDown-CurrentTime>999){
  if(WorkTime==true){
    CurrentTime=millis();WorkingSeconds--;
    if(WorkingSeconds<0){WorkingMinutes--;WorkingSeconds=59;h=WorkingMinutes*5;}
    Minutes(WorkingMinutes);Seconds(WorkingSeconds);DotsDisplay();
    if(WorkingMinutes==0&&WorkingSeconds==10){s=255;v=255;
    Minutes(WorkingMinutes);Seconds(WorkingSeconds);DotsDisplay();
    for(int i=0;i<3;i++){digitalWrite(Bell,HIGH);delay(100);digitalWrite(Bell,LOW);delay(200);}}
    if(WorkingMinutes==0&&WorkingSeconds==0){
    WorkTime=false;RestTime=true;WorkingMinutes=DefinedWorkingMinutes;WorkingSeconds=DefinedWorkingSeconds;h=145;s=230;v=255;for(int i=0;i<5;i++){digitalWrite(Bell,HIGH);delay(14);digitalWrite(Bell,LOW);delay(200);}}
    }
    if(RestTime==true){
       CurrentTime=millis();RestingSeconds--;
       if(RestingSeconds<0){RestingMinutes--;RestingSeconds=59;}
      Minutes(RestingMinutes);Seconds(RestingSeconds);DotsDisplay();
       if(RestingMinutes==0&&RestingSeconds==10){h=130;s=255;v=255;
    Minutes(RestingMinutes);Seconds(RestingSeconds);DotsDisplay();
    for(int i=0;i<3;i++){digitalWrite(Bell,HIGH);delay(100);digitalWrite(Bell,LOW);delay(200);}}
      if(RestingMinutes==0&&RestingSeconds==0){WorkTime=true;RestTime=false;RestingMinutes=DefinedRestingMinutes;RestingSeconds=DefinedRestingSeconds;h=WorkingMinutes*5;s=0;v=180;RoundTotal++;Rounds(RoundTotal);
     digitalWrite(Bell,HIGH);delay(14);digitalWrite(Bell,LOW);}
      
      }
    }
  }

 if(digitalRead(IntervalMode)==HIGH){ShowAnimation=true;}                                                                 /*interval mode*/
while(digitalRead(IntervalMode)==HIGH){
    if(ShowAnimation==true){ClearUserInterface();
   
  for(byte c = 0; c<40;c++){
         h=random(150,255); s=random(200,256); v=random(255);                 
  LedsOnDisplay[0][c]=CHSV(h,s,v);FastLED.show();delay(10);}

for(byte i = 74; i<94;i++){  
  h=random(150,255);  s=random(200,256); v=random(255);              
  LedsOnDisplay[0][i]=CHSV(h,s,v);FastLED.show();delay(10);
  if(i==93){ShowAnimation=false;Serial.println("Interval mode!");h=WorkingMinutes*5;s=0;v=180;Rounds(RoundTotal);Minutes(WorkingMinutes);Seconds(WorkingSeconds);DotsDisplay();
  delay(2000);digitalWrite(Bell,HIGH);delay(14);digitalWrite(Bell,LOW);}}
}
  CountDown=millis();
 Serial.println(CurrentTime);
  if(CountDown-CurrentTime>999){
  if(WorkTime==true){
    CurrentTime=millis();WorkingSeconds--;IntervalCountDown--;Serial.println(IntervalCountDown);
    if(WorkingSeconds<0){WorkingMinutes--;WorkingSeconds=59;h=WorkingMinutes*5;}
    Minutes(WorkingMinutes);Seconds(WorkingSeconds);DotsDisplay();
    if(IntervalCountDown<6){h=75;s=240;v=255;Rounds(IntervalCountDown);h=WorkingMinutes*5;s=0;v=180;}
    if(IntervalCountDown<=0&&WorkingSeconds>5){ digitalWrite(Bell,HIGH);delay(14);digitalWrite(Bell,LOW);IntervalCountDown=IntervalPeriod;Rounds(RoundTotal);}
    if(WorkingMinutes==0&&WorkingSeconds==0){
    WorkTime=false;RestTime=true;WorkingMinutes=DefinedWorkingMinutes;WorkingSeconds=DefinedWorkingSeconds;h=145;s=230;v=255;for(int i=0;i<3;i++){digitalWrite(Bell,HIGH);delay(14);digitalWrite(Bell,LOW);delay(200);}delay(558);Rounds(RoundTotal);}
  
    }
    if(RestTime==true){
       CurrentTime=millis();RestingSeconds--;
       if(RestingSeconds<0){RestingMinutes--;RestingSeconds=59;}
      Minutes(RestingMinutes);Seconds(RestingSeconds);DotsDisplay();
      if(RestingMinutes==0&&RestingSeconds==0){WorkTime=true;RestTime=false;RestingMinutes=DefinedRestingMinutes;RestingSeconds=DefinedRestingSeconds;h=WorkingMinutes*5;s=0;v=180;RoundTotal++;Rounds(RoundTotal);
      digitalWrite(Bell,HIGH);delay(14);digitalWrite(Bell,LOW);IntervalCountDown=IntervalPeriod;}
      } }
    
  }






}
                                                            
                                                             /* Functions from here onwards!*/
 void Seg1(){for(byte i = 0; i<8;i++){                       /*setting up all the segments*/
  LedsOnDisplay[Disp][i]=CHSV(h,s,v);}}
void Seg2(){for(byte i = 8; i<15;i++){
  LedsOnDisplay[Disp][i]=CHSV(h,s,v);}}
 void Seg3(){for(byte i = 15; i<22;i++){
  LedsOnDisplay[Disp][i]=CHSV(h,s,v);}}
  void Seg4(){for(byte i = 22; i<30;i++){
  LedsOnDisplay[Disp][i]=CHSV(h,s,v);}}
  void Seg5(){for(byte i = 30; i<39;i++){
   LedsOnDisplay[Disp][i]=CHSV(h,s,v);}}
   void Seg6(){for(byte i = 39; i<48;i++){
 LedsOnDisplay[Disp][i]=CHSV(h,s,v);}}
 void Seg7(){for(byte i = 48; i<56;i++){
  LedsOnDisplay[Disp][i]=CHSV(h,s,v);}}

  void RoundsDisplay() {h=random(256);                                                               /*setting up user interface displays*/
  for(byte i = 0; i<40;i++){
    h++;                       
  LedsOnDisplay[0][i]=CHSV(h,s,v);}}
  void WorkDisplay(){ h=random(251,23);s=255;v=255;
  for(byte i = 40; i<58;i++){
    h=h+3;                       
  LedsOnDisplay[0][i]=CHSV(h,s,v);FastLED.show();}}
 void SetupDisplay(){h=random(90,110);s=255;v=190;
 for(byte i = 58; i<74;i++){ 
             h=h+3;s=s-2; 
  LedsOnDisplay[0][i]=CHSV(h,s,v);}}
void IntervalDisplay(){
for(byte i = 74; i<94;i++){              
  LedsOnDisplay[0][i]=CHSV(h,s,v);}FastLED.show();}
void PlusDisplay(){for(byte i = 94; i<98;i++){                   
  LedsOnDisplay[0][i]=CHSV(3,205,60);}
            for(byte i = 106; i<111;i++){                   
  LedsOnDisplay[0][i]=CHSV(3,205,60);}FastLED.show();}
void MinusDisplay(){for(byte i = 98; i<106;i++){                   
  LedsOnDisplay[0][i]=CHSV(150,235,120);}FastLED.show();}
void DotsDisplay(){for(byte i = 110; i<112;i++){                   
  LedsOnDisplay[0][i]=CHSV(h,s,v);}FastLED.show();}

                                                                                                                        
  void N0(){Seg2();Seg3();Seg4();Seg5();Seg6();Seg7();}                                                      /*joining various segment functions to form numbers*/
  void N1(){Seg5();Seg6();}
  void N2(){Seg7();Seg6();Seg1();Seg3();Seg4();}
  void N3(){Seg7();Seg6();Seg1();Seg5();Seg4();}
  void N4(){Seg1();Seg2();Seg5();Seg6();}
  void N5(){Seg7();Seg2();Seg1();Seg5();Seg4();}
  void N6(){Seg1();Seg2();Seg3();Seg4();Seg5();Seg7();}
  void N7(){Seg7();Seg6();Seg5();}
  void N8(){Seg1();Seg2();Seg3();Seg4();Seg5();Seg6();Seg7();}
  void N9(){Seg1();Seg2();Seg5();Seg6();Seg7();}



void ClearIntervalDisplay(){for(byte i = 74; i<94;i++){  
  h=(0);  s=(0); v=(0);              
  LedsOnDisplay[0][i]=CHSV(h,s,v);}}
void ClearUserInterface(){fill_solid( LedsOnDisplay[0], NUM_Led, CRGB(0,0,0));FastLED.show();}                                                   /*functions to clear several dysplays*/
void ClearDisp1(){fill_solid( LedsOnDisplay[1], NUM_Led, CRGB(0,0,0));FastLED.show();}
void ClearDisp2(){fill_solid( LedsOnDisplay[2], NUM_Led, CRGB(0,0,0));FastLED.show();}
void ClearDisp3(){fill_solid( LedsOnDisplay[3], NUM_Led, CRGB(0,0,0));FastLED.show();}
void ClearDisp4(){fill_solid( LedsOnDisplay[4], NUM_Led, CRGB(0,0,0));FastLED.show();}
void ClearDisp5(){fill_solid( LedsOnDisplay[5], NUM_Led, CRGB(0,0,0));FastLED.show();}
void ClearDisp6(){fill_solid( LedsOnDisplay[6], NUM_Led, CRGB(0,0,0));FastLED.show();}





void Minutes(int Min){                                                                                                                                /*animations for the numbers shown on the 7 segment displays*/
       switch(Min){
  case 59:ClearDisp3();ClearDisp4();Disp=3;N5();Disp=4;N9();FastLED.show();break;
  case 58:ClearDisp3();ClearDisp4();Disp=3;N5();Disp=4;N8();FastLED.show();break;
   case 57:ClearDisp3();ClearDisp4();Disp=3;N5();Disp=4;N7();FastLED.show();break;
    case 56:ClearDisp3();ClearDisp4();Disp=3;N5();Disp=4;N6();FastLED.show();break;
     case 55:ClearDisp3();ClearDisp4();Disp=3;N5();Disp=4;N5();FastLED.show();break;
      case 54:ClearDisp3();ClearDisp4();Disp=3;N5();Disp=4;N4();FastLED.show();break;
       case 53:ClearDisp3();ClearDisp4();Disp=3;N5();Disp=4;N3();FastLED.show();break;
        case 52:ClearDisp3();ClearDisp4();Disp=3;N5();Disp=4;N2();FastLED.show();break;
         case 51:ClearDisp3();ClearDisp4();Disp=3;N5();Disp=4;N1();FastLED.show();break;
          case 50:ClearDisp3();ClearDisp4();Disp=3;N5();Disp=4;N0();FastLED.show();break;
 case 49:ClearDisp3();ClearDisp4();Disp=3;N4();Disp=4;N9();FastLED.show();break;
  case 48:ClearDisp3();ClearDisp4();Disp=3;N4();Disp=4;N8();FastLED.show();break;
   case 47:ClearDisp3();ClearDisp4();Disp=3;N4();Disp=4;N7();FastLED.show();break;
    case 46:ClearDisp3();ClearDisp4();Disp=3;N4();Disp=4;N6();FastLED.show();break;
     case 45:ClearDisp3();ClearDisp4();Disp=3;N4();Disp=4;N5();FastLED.show();break;
      case 44:ClearDisp3();ClearDisp4();Disp=3;N4();Disp=4;N4();FastLED.show();break;
       case 43:ClearDisp3();ClearDisp4();Disp=3;N4();Disp=4;N3();FastLED.show();break;
        case 42:ClearDisp3();ClearDisp4();Disp=3;N4();Disp=4;N2();FastLED.show();break;
         case 41:ClearDisp3();ClearDisp4();Disp=3;N4();Disp=4;N1();FastLED.show();break;
          case 40:ClearDisp3();ClearDisp4();Disp=3;N4();Disp=4;N0();FastLED.show();break;
 case 39:ClearDisp3();ClearDisp4();Disp=3;N3();Disp=4;N9();FastLED.show();break;
  case 38:ClearDisp3();ClearDisp4();Disp=3;N3();Disp=4;N8();FastLED.show();break;
   case 37:ClearDisp3();ClearDisp4();Disp=3;N3();Disp=4;N7();FastLED.show();break;
    case 36:ClearDisp3();ClearDisp4();Disp=3;N3();Disp=4;N6();FastLED.show();break;
     case 35:ClearDisp3();ClearDisp4();Disp=3;N3();Disp=4;N5();FastLED.show();break;
      case 34:ClearDisp3();ClearDisp4();Disp=3;N3();Disp=4;N4();FastLED.show();break;
       case 33:ClearDisp3();ClearDisp4();Disp=3;N3();Disp=4;N3();FastLED.show();break;
        case 32:ClearDisp3();ClearDisp4();Disp=3;N3();Disp=4;N2();FastLED.show();break;
         case 31:ClearDisp3();ClearDisp4();Disp=3;N3();Disp=4;N1();FastLED.show();break;
          case 30:ClearDisp3();ClearDisp4();Disp=3;N3();Disp=4;N0();FastLED.show();break; 
 case 29:ClearDisp3();ClearDisp4();Disp=3;N2();Disp=4;N9();FastLED.show();break;
  case 28:ClearDisp3();ClearDisp4();Disp=3;N2();Disp=4;N8();FastLED.show();break;
   case 27:ClearDisp3();ClearDisp4();Disp=3;N2();Disp=4;N7();FastLED.show();break;
    case 26:ClearDisp3();ClearDisp4();Disp=3;N2();Disp=4;N6();FastLED.show();break;
     case 25:ClearDisp3();ClearDisp4();Disp=3;N2();Disp=4;N5();FastLED.show();break;
      case 24:ClearDisp3();ClearDisp4();Disp=3;N2();Disp=4;N4();FastLED.show();break;
       case 23:ClearDisp3();ClearDisp4();Disp=3;N2();Disp=4;N3();FastLED.show();break;
        case 22:ClearDisp3();ClearDisp4();Disp=3;N2();Disp=4;N2();FastLED.show();break;
         case 21:ClearDisp3();ClearDisp4();Disp=3;N2();Disp=4;N1();FastLED.show();break;
          case 20:ClearDisp3();ClearDisp4();Disp=3;N2();Disp=4;N0();FastLED.show();break;
 case 19:ClearDisp3();ClearDisp4();Disp=3;N1();Disp=4;N9();FastLED.show();break;
  case 18:ClearDisp3();ClearDisp4();Disp=3;N1();Disp=4;N8();FastLED.show();break;
   case 17:ClearDisp3();ClearDisp4();Disp=3;N1();Disp=4;N7();FastLED.show();break;
    case 16:ClearDisp3();ClearDisp4();Disp=3;N1();Disp=4;N6();FastLED.show();break;
     case 15:ClearDisp3();ClearDisp4();Disp=3;N1();Disp=4;N5();FastLED.show();break;
      case 14:ClearDisp3();ClearDisp4();Disp=3;N1();Disp=4;N4();FastLED.show();break;
       case 13:ClearDisp3();ClearDisp4();Disp=3;N1();Disp=4;N3();FastLED.show();break;
        case 12:ClearDisp3();ClearDisp4();Disp=3;N1();Disp=4;N2();FastLED.show();break;
         case 11:ClearDisp3();ClearDisp4();Disp=3;N1();Disp=4;N1();FastLED.show();break;
          case 10:ClearDisp3();ClearDisp4();Disp=3;N1();Disp=4;N0();FastLED.show();break;
 case 9:ClearDisp3();ClearDisp4();Disp=3;N0();Disp=4;N9();FastLED.show();break;
  case 8:ClearDisp3();ClearDisp4();Disp=3;N0();Disp=4;N8();FastLED.show();break;
   case 7:ClearDisp3();ClearDisp4();Disp=3;N0();Disp=4;N7();FastLED.show();break;
    case 6:ClearDisp3();ClearDisp4();Disp=3;N0();Disp=4;N6();FastLED.show();break;
     case 5:ClearDisp3();ClearDisp4();Disp=3;N0();Disp=4;N5();FastLED.show();break;
      case 4:ClearDisp3();ClearDisp4();Disp=3;N0();Disp=4;N4();FastLED.show();break;
       case 3:ClearDisp3();ClearDisp4();Disp=3;N0();Disp=4;N3();FastLED.show();break;
        case 2:ClearDisp3();ClearDisp4();Disp=3;N0();Disp=4;N2();FastLED.show();break;
         case 1:ClearDisp3();ClearDisp4();Disp=3;N0();Disp=4;N1();FastLED.show();break;
          case 0:ClearDisp3();ClearDisp4();Disp=3;N0();Disp=4;N0();FastLED.show();break;
 }}
void Seconds (int Sec){
switch(Sec){
       case 59:ClearDisp5();ClearDisp6();Disp=5;N5();Disp=6;N9();FastLED.show();break;
      case 58:ClearDisp5();ClearDisp6();Disp=5;N5();Disp=6;N8();FastLED.show();break;
       case 57:ClearDisp5();ClearDisp6();Disp=5;N5();Disp=6;N7();FastLED.show();break;
        case 56:ClearDisp5();ClearDisp6();Disp=5;N5();Disp=6;N6();FastLED.show();break;
         case 55:ClearDisp5();ClearDisp6();Disp=5;N5();Disp=6;N5();FastLED.show();break;
          case 54:ClearDisp5();ClearDisp6();Disp=5;N5();Disp=6;N4();FastLED.show();break;
           case 53:ClearDisp5();ClearDisp6();Disp=5;N5();Disp=6;N3();FastLED.show();break;
            case 52:ClearDisp5();ClearDisp6();Disp=5;N5();Disp=6;N2();FastLED.show();break;
             case 51:ClearDisp5();ClearDisp6();Disp=5;N5();Disp=6;N1();FastLED.show();break;
              case 50:ClearDisp5();ClearDisp6();Disp=5;N5();Disp=6;N0();FastLED.show();break;
       case 49:ClearDisp5();ClearDisp6();Disp=5;N4();Disp=6;N9();FastLED.show();break;
      case 48:ClearDisp5();ClearDisp6();Disp=5;N4();Disp=6;N8();FastLED.show();break;
       case 47:ClearDisp5();ClearDisp6();Disp=5;N4();Disp=6;N7();FastLED.show();break;
        case 46:ClearDisp5();ClearDisp6();Disp=5;N4();Disp=6;N6();FastLED.show();break;
         case 45:ClearDisp5();ClearDisp6();Disp=5;N4();Disp=6;N5();FastLED.show();break;
          case 44:ClearDisp5();ClearDisp6();Disp=5;N4();Disp=6;N4();FastLED.show();break;
           case 43:ClearDisp5();ClearDisp6();Disp=5;N4();Disp=6;N3();FastLED.show();break;
            case 42:ClearDisp5();ClearDisp6();Disp=5;N4();Disp=6;N2();FastLED.show();break;
             case 41:ClearDisp5();ClearDisp6();Disp=5;N4();Disp=6;N1();FastLED.show();break;
              case 40:ClearDisp5();ClearDisp6();Disp=5;N4();Disp=6;N0();FastLED.show();break;
       case 39:ClearDisp5();ClearDisp6();Disp=5;N3();Disp=6;N9();FastLED.show();break;
      case 38:ClearDisp5();ClearDisp6();Disp=5;N3();Disp=6;N8();FastLED.show();break;
       case 37:ClearDisp5();ClearDisp6();Disp=5;N3();Disp=6;N7();FastLED.show();break;
        case 36:ClearDisp5();ClearDisp6();Disp=5;N3();Disp=6;N6();FastLED.show();break;
         case 35:ClearDisp5();ClearDisp6();Disp=5;N3();Disp=6;N5();FastLED.show();break;
          case 34:ClearDisp5();ClearDisp6();Disp=5;N3();Disp=6;N4();FastLED.show();break;
           case 33:ClearDisp5();ClearDisp6();Disp=5;N3();Disp=6;N3();FastLED.show();break;
            case 32:ClearDisp5();ClearDisp6();Disp=5;N3();Disp=6;N2();FastLED.show();break;
             case 31:ClearDisp5();ClearDisp6();Disp=5;N3();Disp=6;N1();FastLED.show();break;
              case 30:ClearDisp5();ClearDisp6();Disp=5;N3();Disp=6;N0();FastLED.show();break;
       case 29:ClearDisp5();ClearDisp6();Disp=5;N2();Disp=6;N9();FastLED.show();break;
      case 28:ClearDisp5();ClearDisp6();Disp=5;N2();Disp=6;N8();FastLED.show();break;
       case 27:ClearDisp5();ClearDisp6();Disp=5;N2();Disp=6;N7();FastLED.show();break;
        case 26:ClearDisp5();ClearDisp6();Disp=5;N2();Disp=6;N6();FastLED.show();break;
         case 25:ClearDisp5();ClearDisp6();Disp=5;N2();Disp=6;N5();FastLED.show();break;
          case 24:ClearDisp5();ClearDisp6();Disp=5;N2();Disp=6;N4();FastLED.show();break;
           case 23:ClearDisp5();ClearDisp6();Disp=5;N2();Disp=6;N3();FastLED.show();break;
            case 22:ClearDisp5();ClearDisp6();Disp=5;N2();Disp=6;N2();FastLED.show();break;
             case 21:ClearDisp5();ClearDisp6();Disp=5;N2();Disp=6;N1();FastLED.show();break;
              case 20:ClearDisp5();ClearDisp6();Disp=5;N2();Disp=6;N0();FastLED.show();break;
       case 19:ClearDisp5();ClearDisp6();Disp=5;N1();Disp=6;N9();FastLED.show();break;
      case 18:ClearDisp5();ClearDisp6();Disp=5;N1();Disp=6;N8();FastLED.show();break;
       case 17:ClearDisp5();ClearDisp6();Disp=5;N1();Disp=6;N7();FastLED.show();break;
        case 16:ClearDisp5();ClearDisp6();Disp=5;N1();Disp=6;N6();FastLED.show();break;
         case 15:ClearDisp5();ClearDisp6();Disp=5;N1();Disp=6;N5();FastLED.show();break;
          case 14:ClearDisp5();ClearDisp6();Disp=5;N1();Disp=6;N4();FastLED.show();break;
           case 13:ClearDisp5();ClearDisp6();Disp=5;N1();Disp=6;N3();FastLED.show();break;
            case 12:ClearDisp5();ClearDisp6();Disp=5;N1();Disp=6;N2();FastLED.show();break;
             case 11:ClearDisp5();ClearDisp6();Disp=5;N1();Disp=6;N1();FastLED.show();break;
              case 10:ClearDisp5();ClearDisp6();Disp=5;N1();Disp=6;N0();FastLED.show();break;
     case 9:ClearDisp5();ClearDisp6();Disp=5;N0();Disp=6;N9();FastLED.show();break;
      case 8:ClearDisp5();ClearDisp6();Disp=5;N0();Disp=6;N8();FastLED.show();break;
       case 7:ClearDisp5();ClearDisp6();Disp=5;N0();Disp=6;N7();FastLED.show();break;
        case 6:ClearDisp5();ClearDisp6();Disp=5;N0();Disp=6;N6();FastLED.show();break;
         case 5:ClearDisp5();ClearDisp6();Disp=5;N0();Disp=6;N5();FastLED.show();break;
          case 4:ClearDisp5();ClearDisp6();Disp=5;N0();Disp=6;N4();FastLED.show();break;
           case 3:ClearDisp5();ClearDisp6();Disp=5;N0();Disp=6;N3();FastLED.show();break;
            case 2:ClearDisp5();ClearDisp6();Disp=5;N0();Disp=6;N2();FastLED.show();break;
             case 1:ClearDisp5();ClearDisp6();Disp=5;N0();Disp=6;N1();FastLED.show();break;
              case 0:ClearDisp5();ClearDisp6();Disp=5;N0();Disp=6;N0();FastLED.show();break;
}}
 void Interval (int Int){
  switch(Int){

   case 60:ClearDisp1();ClearDisp2();Disp=1;N6();Disp=2;N0();FastLED.show();break;
    case 55:ClearDisp1();ClearDisp2();Disp=1;N5();Disp=2;N5();FastLED.show();break;
     case 50:ClearDisp1();ClearDisp2();Disp=1;N5();Disp=2;N0();FastLED.show();break;
      case 45:ClearDisp1();ClearDisp2();Disp=1;N4();Disp=2;N5();FastLED.show();break;
       case 40:ClearDisp1();ClearDisp2();Disp=1;N4();Disp=2;N0();FastLED.show();break;
        case 35:ClearDisp1();ClearDisp2();Disp=1;N3();Disp=2;N5();FastLED.show();break;
         case 30:ClearDisp1();ClearDisp2();Disp=1;N3();Disp=2;N0();FastLED.show();break;
          case 25:ClearDisp1();ClearDisp2();Disp=1;N2();Disp=2;N5();FastLED.show();break;
           case 20:ClearDisp1();ClearDisp2();Disp=1;N2();Disp=2;N0();FastLED.show();break;
            case 15:ClearDisp1();ClearDisp2();Disp=1;N1();Disp=2;N5();FastLED.show();break;
             case 10:ClearDisp1();ClearDisp2();Disp=1;N1();Disp=2;N0();FastLED.show();break;
              case 5:ClearDisp1();ClearDisp2();Disp=1;N0();Disp=2;N5();FastLED.show();break;
}}
void Rounds(int Rnd){
 switch(Rnd){
    case 99:ClearDisp1();ClearDisp2();Disp=1;N9();Disp=2;N9();FastLED.show();break;
  case 98:ClearDisp1();ClearDisp2();Disp=1;N9();Disp=2;N8();FastLED.show();break;
  case 97:ClearDisp1();ClearDisp2();Disp=1;N9();Disp=2;N7();FastLED.show();break;
  case 96:ClearDisp1();ClearDisp2();Disp=1;N9();Disp=2;N6();FastLED.show();break;
  case 95:ClearDisp1();ClearDisp2();Disp=1;N9();Disp=2;N5();FastLED.show();break;
  case 94:ClearDisp1();ClearDisp2();Disp=1;N9();Disp=2;N4();FastLED.show();break;
  case 93:ClearDisp1();ClearDisp2();Disp=1;N9();Disp=2;N3();FastLED.show();break;
  case 92:ClearDisp1();ClearDisp2();Disp=1;N9();Disp=2;N2();FastLED.show();break;
  case 91:ClearDisp1();ClearDisp2();Disp=1;N9();Disp=2;N1();FastLED.show();break;
  case 90:ClearDisp1();ClearDisp2();Disp=1;N9();Disp=2;N0();FastLED.show();break;

   case 89:ClearDisp1();ClearDisp2();Disp=1;N8();Disp=2;N9();FastLED.show();break;
  case 88:ClearDisp1();ClearDisp2();Disp=1;N8();Disp=2;N8();FastLED.show();break;
  case 87:ClearDisp1();ClearDisp2();Disp=1;N8();Disp=2;N7();FastLED.show();break;
  case 86:ClearDisp1();ClearDisp2();Disp=1;N8();Disp=2;N6();FastLED.show();break;
  case 85:ClearDisp1();ClearDisp2();Disp=1;N8();Disp=2;N5();FastLED.show();break;
  case 84:ClearDisp1();ClearDisp2();Disp=1;N8();Disp=2;N4();FastLED.show();break;
  case 83:ClearDisp1();ClearDisp2();Disp=1;N8();Disp=2;N3();FastLED.show();break;
  case 82:ClearDisp1();ClearDisp2();Disp=1;N8();Disp=2;N2();FastLED.show();break;
  case 81:ClearDisp1();ClearDisp2();Disp=1;N8();Disp=2;N1();FastLED.show();break;
  case 80:ClearDisp1();ClearDisp2();Disp=1;N8();Disp=2;N0();FastLED.show();break;

   case 79:ClearDisp1();ClearDisp2();Disp=1;N7();Disp=2;N9();FastLED.show();break;
  case 78:ClearDisp1();ClearDisp2();Disp=1;N7();Disp=2;N8();FastLED.show();break;
  case 77:ClearDisp1();ClearDisp2();Disp=1;N7();Disp=2;N7();FastLED.show();break;
  case 76:ClearDisp1();ClearDisp2();Disp=1;N7();Disp=2;N6();FastLED.show();break;
  case 75:ClearDisp1();ClearDisp2();Disp=1;N7();Disp=2;N5();FastLED.show();break;
  case 74:ClearDisp1();ClearDisp2();Disp=1;N7();Disp=2;N4();FastLED.show();break;
  case 73:ClearDisp1();ClearDisp2();Disp=1;N7();Disp=2;N3();FastLED.show();break;
  case 72:ClearDisp1();ClearDisp2();Disp=1;N7();Disp=2;N2();FastLED.show();break;
  case 71:ClearDisp1();ClearDisp2();Disp=1;N7();Disp=2;N1();FastLED.show();break;
  case 70:ClearDisp1();ClearDisp2();Disp=1;N7();Disp=2;N0();FastLED.show();break;

 
  case 69:ClearDisp1();ClearDisp2();Disp=1;N6();Disp=2;N9();FastLED.show();break;
  case 68:ClearDisp1();ClearDisp2();Disp=1;N6();Disp=2;N8();FastLED.show();break;
  case 67:ClearDisp1();ClearDisp2();Disp=1;N6();Disp=2;N7();FastLED.show();break;
  case 66:ClearDisp1();ClearDisp2();Disp=1;N6();Disp=2;N6();FastLED.show();break;
  case 65:ClearDisp1();ClearDisp2();Disp=1;N6();Disp=2;N5();FastLED.show();break;
  case 64:ClearDisp1();ClearDisp2();Disp=1;N6();Disp=2;N4();FastLED.show();break;
  case 63:ClearDisp1();ClearDisp2();Disp=1;N6();Disp=2;N3();FastLED.show();break;
  case 62:ClearDisp1();ClearDisp2();Disp=1;N6();Disp=2;N2();FastLED.show();break;
  case 61:ClearDisp1();ClearDisp2();Disp=1;N6();Disp=2;N1();FastLED.show();break;
  case 60:ClearDisp1();ClearDisp2();Disp=1;N6();Disp=2;N0();FastLED.show();break;

   case 59:ClearDisp1();ClearDisp2();Disp=1;N5();Disp=2;N9();FastLED.show();break;
  case 58:ClearDisp1();ClearDisp2();Disp=1;N5();Disp=2;N8();FastLED.show();break;
  case 57:ClearDisp1();ClearDisp2();Disp=1;N5();Disp=2;N7();FastLED.show();break;
  case 56:ClearDisp1();ClearDisp2();Disp=1;N5();Disp=2;N6();FastLED.show();break;
  case 55:ClearDisp1();ClearDisp2();Disp=1;N5();Disp=2;N5();FastLED.show();break;
  case 54:ClearDisp1();ClearDisp2();Disp=1;N5();Disp=2;N4();FastLED.show();break;
  case 53:ClearDisp1();ClearDisp2();Disp=1;N5();Disp=2;N3();FastLED.show();break;
  case 52:ClearDisp1();ClearDisp2();Disp=1;N5();Disp=2;N2();FastLED.show();break;
  case 51:ClearDisp1();ClearDisp2();Disp=1;N5();Disp=2;N1();FastLED.show();break;
  case 50:ClearDisp1();ClearDisp2();Disp=1;N5();Disp=2;N0();FastLED.show();break;

  case 49:ClearDisp1();ClearDisp2();Disp=1;N4();Disp=2;N9();FastLED.show();break;
  case 48:ClearDisp1();ClearDisp2();Disp=1;N4();Disp=2;N8();FastLED.show();break;
  case 47:ClearDisp1();ClearDisp2();Disp=1;N4();Disp=2;N7();FastLED.show();break;
  case 46:ClearDisp1();ClearDisp2();Disp=1;N4();Disp=2;N6();FastLED.show();break;
  case 45:ClearDisp1();ClearDisp2();Disp=1;N4();Disp=2;N5();FastLED.show();break;
  case 44:ClearDisp1();ClearDisp2();Disp=1;N4();Disp=2;N4();FastLED.show();break;
  case 43:ClearDisp1();ClearDisp2();Disp=1;N4();Disp=2;N3();FastLED.show();break;
  case 42:ClearDisp1();ClearDisp2();Disp=1;N4();Disp=2;N2();FastLED.show();break;
  case 41:ClearDisp1();ClearDisp2();Disp=1;N4();Disp=2;N1();FastLED.show();break;
  case 40:ClearDisp1();ClearDisp2();Disp=1;N4();Disp=2;N0();FastLED.show();break;

  case 39:ClearDisp1();ClearDisp2();Disp=1;N3();Disp=2;N9();FastLED.show();break;
  case 38:ClearDisp1();ClearDisp2();Disp=1;N3();Disp=2;N8();FastLED.show();break;
  case 37:ClearDisp1();ClearDisp2();Disp=1;N3();Disp=2;N7();FastLED.show();break;
  case 36:ClearDisp1();ClearDisp2();Disp=1;N3();Disp=2;N6();FastLED.show();break;
  case 35:ClearDisp1();ClearDisp2();Disp=1;N3();Disp=2;N5();FastLED.show();break;
  case 34:ClearDisp1();ClearDisp2();Disp=1;N3();Disp=2;N4();FastLED.show();break;
  case 33:ClearDisp1();ClearDisp2();Disp=1;N3();Disp=2;N3();FastLED.show();break;
  case 32:ClearDisp1();ClearDisp2();Disp=1;N3();Disp=2;N2();FastLED.show();break;
  case 31:ClearDisp1();ClearDisp2();Disp=1;N3();Disp=2;N1();FastLED.show();break;
  case 30:ClearDisp1();ClearDisp2();Disp=1;N3();Disp=2;N0();FastLED.show();break;
  
  case 29:ClearDisp1();ClearDisp2();Disp=1;N2();Disp=2;N9();FastLED.show();break;
  case 28:ClearDisp1();ClearDisp2();Disp=1;N2();Disp=2;N8();FastLED.show();break;
  case 27:ClearDisp1();ClearDisp2();Disp=1;N2();Disp=2;N7();FastLED.show();break;
  case 26:ClearDisp1();ClearDisp2();Disp=1;N2();Disp=2;N6();FastLED.show();break;
  case 25:ClearDisp1();ClearDisp2();Disp=1;N2();Disp=2;N5();FastLED.show();break;
  case 24:ClearDisp1();ClearDisp2();Disp=1;N2();Disp=2;N4();FastLED.show();break;
  case 23:ClearDisp1();ClearDisp2();Disp=1;N2();Disp=2;N3();FastLED.show();break;
  case 22:ClearDisp1();ClearDisp2();Disp=1;N2();Disp=2;N2();FastLED.show();break;
  case 21:ClearDisp1();ClearDisp2();Disp=1;N2();Disp=2;N1();FastLED.show();break;
  case 20:ClearDisp1();ClearDisp2();Disp=1;N2();Disp=2;N0();FastLED.show();break;

  case 19:ClearDisp1();ClearDisp2();Disp=1;N1();Disp=2;N9();FastLED.show();break;
  case 18:ClearDisp1();ClearDisp2();Disp=1;N1();Disp=2;N8();FastLED.show();break;
  case 17:ClearDisp1();ClearDisp2();Disp=1;N1();Disp=2;N7();FastLED.show();break;
  case 16:ClearDisp1();ClearDisp2();Disp=1;N1();Disp=2;N6();FastLED.show();break;
  case 15:ClearDisp1();ClearDisp2();Disp=1;N1();Disp=2;N5();FastLED.show();break;
  case 14:ClearDisp1();ClearDisp2();Disp=1;N1();Disp=2;N4();FastLED.show();break;
  case 13:ClearDisp1();ClearDisp2();Disp=1;N1();Disp=2;N3();FastLED.show();break;
  case 12:ClearDisp1();ClearDisp2();Disp=1;N1();Disp=2;N2();FastLED.show();break;
  case 11:ClearDisp1();ClearDisp2();Disp=1;N1();Disp=2;N1();FastLED.show();break;
  case 10:ClearDisp1();ClearDisp2();Disp=1;N1();Disp=2;N0();FastLED.show();break;
  
  case 9:ClearDisp1();ClearDisp2();Disp=1;N0();Disp=2;N9();FastLED.show();break;
  case 8:ClearDisp1();ClearDisp2();Disp=1;N0();Disp=2;N8();FastLED.show();break;
  case 7:ClearDisp1();ClearDisp2();Disp=1;N0();Disp=2;N7();FastLED.show();break;
  case 6:ClearDisp1();ClearDisp2();Disp=1;N0();Disp=2;N6();FastLED.show();break;
  case 5:ClearDisp1();ClearDisp2();Disp=1;N0();Disp=2;N5();FastLED.show();break;
  case 4:ClearDisp1();ClearDisp2();Disp=1;N0();Disp=2;N4();FastLED.show();break;
  case 3:ClearDisp1();ClearDisp2();Disp=1;N0();Disp=2;N3();FastLED.show();break;
  case 2:ClearDisp1();ClearDisp2();Disp=1;N0();Disp=2;N2();FastLED.show();break;
  case 1:ClearDisp1();ClearDisp2();Disp=1;N0();Disp=2;N1();FastLED.show();break;
  case 0:ClearDisp1();ClearDisp2();Disp=1;N0();Disp=2;N0();FastLED.show();break;
  }
}
