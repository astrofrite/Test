bool B2;
float pos = 0;
long ttimer = 0;
long timer1 = 0;
long timer2 = 0;
long timetrans = 0;
float temp = 0;
float tension = 0;
float imagetension =0;

// the setup function runs once when you press reset or power the board
void setup()
{
  pinMode(3, INPUT);
  pinMode(11,OUTPUT);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop()
{


  B2 = digitalRead(3);
  do
  {
    B2 = digitalRead(3);
  }
  while(B2 == LOW);

  timer1 = micros();
  do
  {
    B2 = digitalRead(3);
  }
  while (B2 == HIGH);
  timer2 = micros();

  ttimer = timer2 - timer1;



  ttimer = ttimer - 1000;
  pos = ttimer * 0.090;

  if (timer1 = timetrans + 500000)
  {

    Serial.print("pos = ");
    Serial.println(pos);
    temp = (ttimer*7/200) ;
    Serial.print("temp = ");
    Serial.println(temp);

    imagetension = (temp * 1023.0/5.0)/4;

    analogWrite(11, imagetension);
    timetrans = timer1;
  }






}
