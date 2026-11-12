
const int TRIG_PIN = 9;
const int ECHO_PIN = 10;
const int RED_LED   = 1;  
const int YEL_LED   = 2; 
const int GRN_LED   = 3;  
const int FAR_THRESHOLD = 30;   
const int NEAR_THRESHOLD = 15;  
void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(YEL_LED, OUTPUT);
  pinMode(GRN_LED, OUTPUT);
}
void loop() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  long duration = pulseIn(ECHO_PIN, HIGH);
  float distanceCm = duration * 0.0343 / 2.0;
  if (distanceCm <= 0 || distanceCm > 400) {
    setLEDs(LOW, LOW, LOW);
  } else if (distanceCm < NEAR_THRESHOLD) {
    setLEDs(HIGH, LOW, LOW);
  } else if (distanceCm <= FAR_THRESHOLD) {
    setLEDs(LOW, HIGH, LOW);
  } else {
    setLEDs(LOW, LOW, HIGH);
  }
  Serial.println(distanceCm);
  delay(100);
}
void setLEDs(int redState, int yellowState, int greenState) {
  digitalWrite(RED_LED, redState);
  digitalWrite(YEL_LED, yellowState);
  digitalWrite(GRN_LED, greenState);
}