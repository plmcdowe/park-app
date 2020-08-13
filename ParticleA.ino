#define echoPin D6 // Echo Pin
#define trigPin D2 // Trigger Pin

int maximumRange = 5; // Maximum range for reading
int minimumRange = 0; // Minimum range for reading
unsigned int cars = 100; //Number of spaces available in garage
long duration, distance; // Duration used to calculate distanc

char val[40];

void setup() {
 Particle.subscribe("sub", myHandler);
 Serial.begin (9600);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
}

//void handler that listens for "trig" from ParticleB; when "trig" recieved, count++ in cars
void myHandler(const char *event, const char *data) {
    
    if (strcmp(data, "trig")==0) {
        cars++;
        sprintf(val, "%u", cars);
        Particle.publish("count", val, PUBLIC);
    }
}

//void loop that watches for signal from sensor, when the sensor is tripped, count is reduced by one.
void loop() {
 digitalWrite(trigPin, LOW);
 delayMicroseconds(2);

 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10); 

 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 distance = duration/58.2;

 if (distance <= maximumRange){
    cars --;
    sprintf(val, "%u", cars);
    Particle.publish("count", val, PUBLIC);
    }
 
 //Delay in ms before next reading --> 10 second.
 delay(10000);
 }