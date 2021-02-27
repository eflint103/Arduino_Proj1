int analogPin = A0;
int val = 0;
int state = 2;
int speakerPin = 12;
int numTones = 15;
int tones[] = {261, 277, 294, 311, 330, 349, 370, 392, 415, 440};
//            mid C  C#   D    D#   E    F    F#   G    G#   A
int toneswin[] = {392,494,587,784,988,415,523,622,831,1047,466,587,698,932,1175};
int toneslose[] = {440,494,554,587,659,698,659,659,587,698,587,587,659,392,349};
bool up = true;
void setup() {
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(11,OUTPUT);
}

void loop() {
  val = analogRead(analogPin);  // read the input pin
  if (val>=660){//button is pressed firmly
    if (up){
      digitalWrite((state-1),LOW);
    }
    else{
      digitalWrite((state+1),LOW);
    }  
    if (state==5){
      for (int i = 0; i < numTones; i++){
        tone(speakerPin, toneswin[i]);
        if (i%2==0){
          digitalWrite(state,HIGH);
        }
        else{
          digitalWrite(state,LOW);
        }
        delay(100);
      }
    noTone(speakerPin);
    }
    else{
      for (int i = 0; i < numTones; i++){
        tone(speakerPin, toneslose[i]);
        if (i%2==0){
          digitalWrite(state,HIGH);
        }
        else{
          digitalWrite(state,LOW);
        }
        delay(100);
      }
    noTone(speakerPin);
    }
  }
  if (up){
    digitalWrite(state,HIGH);
    digitalWrite((state-1),LOW);
    if (state==8){
      state--;
      up=false;
    }
    else{
      state++;
    }
  }
  else{
    digitalWrite(state,HIGH);
    digitalWrite((state+1),LOW);
    if (state==2){
      state++;
      up=true;
    }
    else{
      state--;
    }
  }
  delay(100);
}
