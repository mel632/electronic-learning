
// ECG with averaging: removes 50 Hz hum, shows ~2 s per window

void setup() {
  Serial.begin(115200);
  pinMode(10, INPUT);
  pinMode(11, INPUT);
}

void loop() {
  if (digitalRead(10) == HIGH || digitalRead(11) == HIGH) {
    Serial.println(0);            // an electrode is off
    delay(40);
  } else {
    long sum = 0;
    for (int i = 0; i < 20; i++) {  // 20 readings × 2 ms = 40 ms
      sum = sum + analogRead(A0);
      delay(2);
    }
    Serial.println(sum / 20);     // print the average
  }
}
