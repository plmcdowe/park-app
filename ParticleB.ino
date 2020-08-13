#define echoPin D6 // Echo Pin
#define trigPin D2 // Trigger Pin

int maximumRange = 5; // Maximum range for reading
int minimumRange = 0; // Minimum range for reading
long duration, distance; // Duration used to calculate distance

void setup() {
 Serial.begin (9600);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
}

//void loop that watches for signal from sensor, when the sensor is tripped, Particle.publish sends "trig"; making PartcleA add to count.
void loop() {
 digitalWrite(trigPin, LOW);
 delayMicroseconds(2);

 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10); 

 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 distance = duration/58.2;

 if (distance <= maximumRange){
 
 Particle.publish("sub", "trig");
 }

 //Delay in ms before next reading --> 10 second.
 delay(10000);
} 