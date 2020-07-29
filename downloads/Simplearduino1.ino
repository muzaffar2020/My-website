const int led_pin = 13;
const int button_pin = 7;
int button_state = 0;
void setup(){
  pinMode(led_pin , OUTPUT);
  pinMode(button_pin, INPUT_PULLUP);
  digitalWrite(led_pin , LOW);
}

void loop(){
  button_state = digitalRead( button_pin);

  if(button_state == LOW){
    digitalWrite(led_pin, HIGH);
  }else{
    digitalWrite(led_pin, LOW);
  }
}
