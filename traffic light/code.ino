// Traffic light: green on pin 2, yellow on pin 3, red on pin 4

const int GREEN = 2;
const int YELLOW = 3;
const int RED = 4;

void setup() {
  pinMode(GREEN, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(RED, OUTPUT);
}

void loop() {
  digitalWrite(GREEN, HIGH);   // green for 5 s
  delay(2000);
  digitalWrite(GREEN, LOW);

  digitalWrite(YELLOW, HIGH);  // yellow for 2 s
  delay(1000);
  digitalWrite(YELLOW, LOW);

  digitalWrite(RED, HIGH);     // red for 5 s
  delay(2000);
  digitalWrite(RED, LOW);
}