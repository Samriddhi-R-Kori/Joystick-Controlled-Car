int ena = 9;
int m1p1 = 4;
int m1p2 = 5;

int enb = 10;
int m2p1 = 6;
int m2p2 = 7;

int xp = A1;
int yp = A0;
int xv;
int yv;
int sw = 2;
int sv;

void setup()
{
  Serial.begin(9600);

  pinMode(ena, OUTPUT);
  pinMode(enb, OUTPUT);
  pinMode(m1p1, OUTPUT);
  pinMode(m1p2, OUTPUT);
  pinMode(m2p1, OUTPUT);
  pinMode(m2p2, OUTPUT);

  pinMode(xp, INPUT);
  pinMode(yp, INPUT);
  pinMode(sw, INPUT);
  digitalWrite(sw, HIGH);
}

void loop()
{
  xv = analogRead(xp);
  yv = analogRead(yp);
  sv = digitalRead(sw);
  delay(200);
  Serial.print("x=");
  Serial.print(xv);
  Serial.print(" y=");
  Serial.println(yv);
  //Serial.println(sv);

  if (sv == 1)
  {
    if (xv > 550)
    {
      Serial.println("forward");
      digitalWrite(m1p1, HIGH);
      digitalWrite(m1p2, LOW);
      digitalWrite(m2p1, LOW);
      digitalWrite(m2p2, HIGH);
      analogWrite(ena, 255);
      analogWrite(enb, 255);
    }
    if (xv < 490)
    {
      Serial.println("backward");
      digitalWrite(m1p1, LOW);
      digitalWrite(m1p2, HIGH);
      digitalWrite(m2p1, HIGH);
      digitalWrite(m2p2, LOW);
      analogWrite(ena, 255);
      analogWrite(enb, 255);
    }
    if (yv > 540)
    {
      Serial.println("right");
      digitalWrite(m1p1, LOW);
      digitalWrite(m1p2, HIGH);
      digitalWrite(m2p1, LOW);
      digitalWrite(m2p2, LOW);
      analogWrite(ena, 255);
      analogWrite(enb, 0);
    }
    if (yv < 500)
    {
      Serial.println("left");
      digitalWrite(m1p1, LOW);
      digitalWrite(m1p2, LOW);
      digitalWrite(m2p1, HIGH);
      digitalWrite(m2p2, LOW);
      analogWrite(ena, 0);
      analogWrite(enb, 255);
    }
    if (xv > 490 && xv < 550 && yv > 500 && yv < 540 )
    {
      Serial.println("Stop");
      digitalWrite(m1p1, LOW);
      digitalWrite(m1p2, LOW);
      digitalWrite(m2p1, LOW);
      digitalWrite(m2p2, LOW);
      analogWrite(ena, 0);
      analogWrite(enb, 0);
    }
  }
  else if (sv == 0)
  {
    Serial.println("Stop");
    digitalWrite(m1p1, LOW);
    digitalWrite(m1p2, LOW);
    digitalWrite(m2p1, LOW);
    digitalWrite(m2p2, LOW);
    analogWrite(ena, 0);
    analogWrite(enb, 0);
    sv=1;
  }

}
