#include <stdio.h>
#include <WiringPi.h>

int main(int argc, char *argv[])
{
    wiringPiSetup () ;
    pinMode(0, INPUT);
    pinMode(1, OUTPUT);
    pinMode(2, OUTPUT);
    while(1) {
        digitalWrite(1,LOW);
        digitalWrite(2,LOW);
        printf("Waiting for reset\n");
        while(digitalRead(0) == 1);
        digitalWrite(1, LOW);
        digitalWrite(2, HIGH);
        delay(50);
        digitalWrite(2, LOW);
        /*ifttt("http://red.eecs.yorku.ca:8080/trigger/event/with/key/123", "jl$
         */printf("Waiting for event\n");
        while(digitalRead(0) == 0);
        digitalWrite(1,HIGH);
        digitalWrite(2, LOW);
        delay(50);
        digitalWrite(1,LOW);
        printf("Alarm\n");
    }
    /*NOTREACHED*/
    return 0;
}
