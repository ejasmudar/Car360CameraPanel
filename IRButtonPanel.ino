
#include<arduino.h>


unsigned int IROn[68] = {9080,4470, 580,570, 580,570, 530,570, 580,570, 580,570, 530,570, 580,570, 580,570, 530,1720, 580,1670, 580,1670, 580,1720, 530,1720, 580,1670, 580,1670, 580,1720, 530,570, 580,570, 580,570, 530,570, 580,570, 580,570, 530,570, 580,570, 580,1670, 580,1670, 580,1720, 530,1720, 580,1670, 580,1670, 580,1720, 530,1720, 580};
unsigned int IRUp[68] = {9030,4520, 530,570, 530,620, 530,620, 530,570, 580,570, 530,620, 530,570, 580,570, 530,1720, 580,1720, 530,1720, 530,1720, 530,1720, 580,1720, 530,1720, 530,1720, 530,1720, 580,570, 530,620, 530,570, 530,620, 530,620, 480,620, 580,570, 530,620, 530,1720, 530,1720, 580,1670, 580,1720, 530,1720, 530,1720, 580,1670, 580};
unsigned int IRLeft[68] = {9030,4570, 530,570, 530,620, 530,620, 530,570, 530,620, 530,620, 530,570, 580,570, 530,1720, 530,1720, 580,1720, 530,1720, 530,1720, 530,1720, 580,1720, 480,1770, 530,620, 530,570, 530,1770, 530,570, 580,570, 530,620, 530,570, 530,620, 530,1720, 530,1720, 580,570, 530,1720, 580,1720, 530,1720, 530,1720, 530,1720, 580};
unsigned int IRRight[68] = {9080,4520, 530,570, 580,570, 580,570, 530,570, 580,570, 580,570, 530,570, 580,570, 580,1670, 580,1670, 580,1720, 530,1720, 580,1670, 580,1670, 580,1720, 530,1720, 580,570, 530,1720, 580,1670, 580,570, 580,520, 580,570, 580,570, 580,520, 580,1720, 530,570, 580,570, 580,1670, 580,1670, 580,1720, 580,1670, 580,1670, 580};
unsigned int IRDown[68] = {9080,4470, 580,570, 580,570, 530,570, 580,570, 580,570, 530,570, 580,570, 530,620, 530,1720, 530,1720, 530,1720, 580,1720, 530,1720, 530,1720, 530,1720, 580,1720, 530,1720, 530,620, 530,570, 580,1670, 580,570, 580,570, 530,570, 580,570, 580,570, 530,1720, 530,1720, 580,570, 530,1720, 580,1720, 530,1720, 530,1720, 530};

const int Output360Pin = 3;
const int Button360On = 4;
const int Button360Left = 5;
const int Button360Right = 6;


int State_Button360On =0;
int State_Button360Left  =0;
int State_Button360Right =0;


void setup() {
  // put your setup code here, to run once:
pinMode(Output360Pin, OUTPUT);
pinMode(Button360On, INPUT_PULLUP);
pinMode(Button360Left, INPUT_PULLUP);
pinMode(Button360Right, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
 State_Button360On = digitalRead(Button360On);
 State_Button360Left = digitalRead(Button360Left);
 State_Button360Right = digitalRead(Button360Right);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (State_Button360On  == LOW) {
    Serial.println("1");
    delay(200);
    SendIRCommand(1);
  } else if (State_Button360Left  == LOW) {
    Serial.println("2");
    delay(200);
    SendIRCommand(2);  
  } else if (State_Button360Right  == LOW) {
    SendIRCommand(3);
    delay(200);
    Serial.println("3");
  }
}



void SendIRCommand(int Command){
  
Serial.println(Command);

unsigned int IRCommand[68];

switch (Command){
  case 1:
    memcpy(IRCommand, IROn, sizeof(IROn[0])*68);
    
    break;
  
  case 2:
    memcpy(IRCommand, IROn, sizeof(IRLeft[0])*68);
    break;

  case 3:
    memcpy(IRCommand, IRRight, sizeof(IROn[0])*68);    
    break;

  Default:
  break;
}


for (int i = 0; i < 68; i++) {
  if (i % 2) { //Set Mark
    digitalWrite(Output360Pin, HIGH);
    delayMicroseconds( IRCommand[i] );
  }
  else {
    digitalWrite(Output360Pin, LOW);
    delayMicroseconds( IRCommand[i] );    
  }
    
}

}
