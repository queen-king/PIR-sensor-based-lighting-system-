int light = 0; // store the current light value
int pirPin = 2;
int pirStat = 0;
void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600); //configure serial to talk to computer
    pinMode(13, OUTPUT); // configure digital pin 13 as an output
    pinMode(pirPin, INPUT);
}

void loop() {
    // put your main code here, to run repeatedly:
    light = analogRead(A0); // read and save value from PR
    
    Serial.println(light); // print current light value
 
    if(light > 100) { // If it is bright...
        Serial.println("It is quite light!");
        digitalWrite(13,LOW); //turn left LED off
    }
    else { // If it's dark...
        Serial.println("It is pretty dark!");
        pirStat = digitalRead(pirPin);
        if(pirStat==HIGH)
        {
          digitalWrite(13,HIGH);
          delay(10000);
        }
        else
        {
          digitalWrite(13,LOW);
        }
    }
    delay(1000); // don't spam the computer!
}
