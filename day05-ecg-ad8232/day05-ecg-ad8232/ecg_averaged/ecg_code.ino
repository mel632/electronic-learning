// ECG without filtering: shows the raw signal, including 50 Hz mains hum
// Board: Arduino Uno + AD8232
// Wiring: OUTPUT -> A0, LO+ -> pin 10, LO- -> pin 11, 3.3V -> 3.3V, GND -> GND
// Serial Plotter at 115200 baud: about 0.25 s per window, so the
// fast 50 Hz wave (one cycle every 20 ms) is clearly visible.

void setup() {
  Serial.begin(115200);
  pinMode(10, INPUT);   // LO+: HIGH when the LA (yellow) electrode is off
  pinMode(11, INPUT);   // LO-: HIGH when the RA (red) electrode is off
}

void loop() {
  if (digitalRead(10) == HIGH || digitalRead(11) == HIGH) {
    Serial.println(0);               // an electrode is off
  } else {
    Serial.println(analogRead(A0));  // raw ECG signal, hum included
  }
  delay(2);                          // one point every ~2-3 ms
}
