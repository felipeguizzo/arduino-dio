const int sensorPin = A0;
int sensorValue = 0;
float temperatureC = 0.0;
const int motor = 3;
const int led = 5;
const int buzzer = 4;

void setup() {
  // Inicializa a comunicação serial
  Serial.begin(9600);
  pinMode(motor, OUTPUT);  
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  sensorValue = analogRead(sensorPin);
  temperatureC = (sensorValue * 5.0 / 1024.0 - 0.5) * 100.0;
  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.println(" C");

  if (temperatureC >= 30){
	analogWrite(motor, 255);
  } else {
 	analogWrite(motor, 0);	
  }
  
  if (temperatureC > 50){
	analogWrite(led, HIGH);
    tone(buzzer, 1000);
    delay(100);
    noTone(buzzer);
    delay(100);
  } else {
 	analogWrite(led, LOW);	
    noTone(buzzer);
  }
  
  delay(1000);
}
