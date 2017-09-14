// pin 1 input from door (open-) 1k pull up
// pin 0 out interior lights-
// pin 2 (A1) Input From LDR

int HYS = 10;
int ledPin1 = 0;
int LDR1 = A1;
int LDRValue1 = 0;
int light_sensitivity1 = 25;
int light1 = 0;
void setup()
 {
  pinMode( 1, INPUT);
 }
void loop()
{
LDRValue1 = analogRead(LDR1);
int light1 = map(LDRValue1, 0, 1012, 0, 100);
static int fadeValue1 = 0;
 if ((light1 < light_sensitivity1 + HYS) && (digitalRead(1) == LOW))
  {
   if (fadeValue1 < 255)
   {
    fadeValue1++;
     analogWrite(ledPin1,fadeValue1);
     delay(15);
   }
  }
if ((light1 > light_sensitivity1 - HYS) || (digitalRead(1) == HIGH))
 {
  if (fadeValue1 > 0)
   { fadeValue1--;
    analogWrite(ledPin1,fadeValue1);
    delay(20);
   }
  }
}

