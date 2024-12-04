int tx1 = 11;
int tx2 = 12;
int tx3 = 13;

int xp = A1;
int yp = A0;
int xv;
int yv;
int sw = 2;
int sv;

void setup()
{
  Serial.begin(9600);
  pinMode(xp, INPUT);
  pinMode(yp, INPUT);
  pinMode(sw, INPUT);
  digitalWrite(sw, HIGH);

  digitalWrite(tx1, LOW); //0
  digitalWrite(tx2, LOW); //0
  digitalWrite(tx3, LOW); //0
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
  Serial.print(yv);
  Serial.print(" sw=");
  Serial.println(sv);

 /* if (sv == 1)
  {
    digitalWrite(tx1, HIGH);//1
    digitalWrite(tx2, HIGH);//1
    digitalWrite(tx3, HIGH);//1
    Serial.print(tx1);
    Serial.print(tx2);
    Serial.println(tx3);*/

    if (xv > 550)//forward
    {
      Serial.println("forward");
      digitalWrite(tx1, LOW);//1
      digitalWrite(tx2, HIGH);//0
      digitalWrite(tx3, HIGH);//0
      Serial.print(tx1);
      Serial.print(tx2);
      Serial.println(tx3);
    }
    if (xv < 490)//backward
    {
      Serial.println("backward");
      digitalWrite(tx1, HIGH);//0
      digitalWrite(tx2, HIGH);//0
      digitalWrite(tx3, LOW);//1
      Serial.print(tx1);
      Serial.print(tx2);
      Serial.println(tx3);
    }
    if (yv > 540)//right
    {
      Serial.println("right");
      digitalWrite(tx1, LOW); //1
      digitalWrite(tx2, LOW);//1
      digitalWrite(tx3, HIGH);//0
      Serial.print(tx1);
      Serial.print(tx2);
      Serial.println(tx3);
    }
    if (yv < 500)//left
    {
      Serial.println("left");
      digitalWrite(tx1, HIGH); //0
      digitalWrite(tx2, LOW);//1
      digitalWrite(tx3, LOW);//1
      Serial.print(tx1);
      Serial.print(tx2);
      Serial.println(tx3);
    }
    if (xv > 490 && xv < 550 && yv > 500 && yv < 540 )
    {
      Serial.println("stop");
      digitalWrite(tx1, LOW);//1
      digitalWrite(tx2, HIGH);//0
      digitalWrite(tx3, LOW);//1
      Serial.print(tx1);
      Serial.print(tx2);
      Serial.println(tx3);
    }
  
  if (sv == 0)
  {
    Serial.println("stop");
    digitalWrite(tx1, LOW);//1
    digitalWrite(tx2, HIGH);//0
    digitalWrite(tx3, LOW);//1
    Serial.print(tx1);
    Serial.print(tx2);
    Serial.println(tx3);
    sv = 1;
  }
}
