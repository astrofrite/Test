int Sortie_sevo = 13;
int potar = A0;

float sensorValue=0;
float voltage =0;

float Temperature = 0;
float Temp_Anc = 0;

long Timer = 0;
long AncTimer_1 = 0;

long Timer_2 = 0;
long AncTimer_2 = 0;


void setup() {
  pinMode(Sortie_sevo,OUTPUT);
  pinMode(potar,INPUT);
  Serial.begin(9600);
}

void loop() {
  
  sensorValue = analogRead(A0);
  voltage = sensorValue * (5.0 / 1023.0);
  Temperature = voltage*7;
   
  servo(Temperature);
  Timer_2=micros();
  
  if(Timer>AncTimer_1+500)
  {
     Serial.println(Temperature);
  }
}

/***Fonction*du*servo***/
void servo(float temperature)
{
  float tp = (200/7)*temperature+1000;
  
  Timer=micros();
  if (Timer>AncTimer_1+tp)
  {
     digitalWrite(Sortie_sevo, LOW);
  }
  if (Timer>AncTimer_1+20000)
  {
     digitalWrite(Sortie_sevo, HIGH);
     AncTimer_1=Timer;
  }
}

