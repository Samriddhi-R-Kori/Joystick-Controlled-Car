int ena = 9;
int m1p1 = 4;
int m1p2 = 5;

int enb = 10;
int m2p1 = 6;
int m2p2 = 7;

int r1, r2, r3;
int rx1 = 11;
int rx2 = 12;
int rx3 = 13;

void setup()
{
  Serial.begin(9600);

  pinMode(ena, OUTPUT);
  pinMode(enb, OUTPUT);
  pinMode(m1p1, OUTPUT);
  pinMode(m1p2, OUTPUT);
  pinMode(m2p1, OUTPUT);
  pinMode(m2p2, OUTPUT);

  digitalWrite(rx1, LOW); //0
  digitalWrite(rx2, LOW); //0
  digitalWrite(rx3, LOW); //0
}

void loop()
{
  r1 = digitalRead(rx1);
  r2 = digitalRead(rx2);
  r3 = digitalRead(rx3);
  Serial.print(r1);
  Serial.print(r2);
  Serial.println(r3);
  
 // if (r1 == 1 && r2 == 1 && r3 == 1)
  //{
    if (r1 == 1 && r2 == 0 && r3 == 0)
    {
      Serial.println("forward");
      digitalWrite(m1p1, HIGH);
      digitalWrite(m1p2, LOW);
      digitalWrite(m2p1, LOW);
      digitalWrite(m2p2, HIGH);
      analogWrite(ena, 255);
      analogWrite(enb, 255);
    }
    if (r1 == 0 && r2 == 0 && r3 == 0)
    {
      Serial.println("backward");
      digitalWrite(m1p1, LOW);
      digitalWrite(m1p2, HIGH);
      digitalWrite(m2p1, HIGH);
      digitalWrite(m2p2, LOW);
      analogWrite(ena, 255);
      analogWrite(enb, 255);
    }
    if (r1 == 1 && r2 == 1 && r3 == 0)
    {
      Serial.println("right");
      digitalWrite(m1p1, LOW);
      digitalWrite(m1p2, HIGH);
      digitalWrite(m2p1, LOW);
      digitalWrite(m2p2, LOW);
      analogWrite(ena, 255);
      analogWrite(enb, 0);
    }
    if (r1 == 0 && r2 == 1 && r3 == 0)
    {
      Serial.println("left");
      digitalWrite(m1p1, LOW);
      digitalWrite(m1p2, LOW);
      digitalWrite(m2p1, HIGH);
      digitalWrite(m2p2, LOW);
      analogWrite(ena, 0);
      analogWrite(enb, 255);
    }
    else if (r1 == 1 && r2 == 0 && r3 == 1)
    {
      Serial.println("Stop");
      digitalWrite(m1p1, LOW);
      digitalWrite(m1p2, LOW);
      digitalWrite(m2p1, LOW);
      digitalWrite(m2p2, LOW);
      analogWrite(ena, 0);
      analogWrite(enb, 0);
    }

//  }
  /*else if (r1 == 1 && r2 == 0 && r3 == 1)
  {
    Serial.println("Stop");
    digitalWrite(m1p1, LOW);
    digitalWrite(m1p2, LOW);
    digitalWrite(m2p1, LOW);
    digitalWrite(m2p2, LOW);
    analogWrite(ena, 0);
    analogWrite(enb, 0);
  }*/
}
