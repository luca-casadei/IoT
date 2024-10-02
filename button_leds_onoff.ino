#define LED_1 7
#define LED_2 6
#define LED_3 5
#define LED_4 4
#define DELAY 100
#define BTN_PIN 2
#define N_LEDS 4

/* The current pin to be activated. */
int curr_pin;
/* Saves the PIN numbers */
int * pins;
/* The states of the LEDS */
int * states;

void setup() {
  Serial.begin(9600);
  pins = malloc(sizeof(int) * 4);
  states = malloc(sizeof(int) * 4);
  curr_pin = 0;
  pinMode(BTN_PIN, INPUT);
  pins[0] = LED_1;
  pins[1] = LED_2;
  pins[2] = LED_3;
  pins[3] = LED_4;
  int i = 0;
  for(i = 0; i < N_LEDS; i++){
    states[i] = LOW;
    pinMode(pins[i], OUTPUT);
  }
}

void loop() {
  /* Reads the button's input */
  int btn_state = digitalRead(BTN_PIN);
  /* Sets the button on and off. */
  if (btn_state == HIGH){
    if (states[curr_pin] == HIGH){
      digitalWrite(pins[curr_pin], LOW);
      states[curr_pin] = LOW;
    }else{
      digitalWrite(pins[curr_pin], HIGH);
      states[curr_pin] = HIGH;
    }
    curr_pin = (curr_pin + 1) % N_LEDS;
  }
  delay(DELAY);
}
