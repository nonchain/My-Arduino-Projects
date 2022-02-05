//Tech Maker
// Subscribe : https://www.youtube.com/channel/UCX-zqect0_tlU6Qwn6GNKcA

int led[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int input, i;
void setup()
{
  for (i = 0; i < 11; i++)
    pinMode(led[i], OUTPUT);
  //Serial.begin(9600);
}
void loop()
{
  input = analogRead(A0);
  //Serial.println(s);
  input = input / 12;      //By changing the denomintor the sensitivity can be changed
  if (input < 12)
  {
    if (input == 0)
    {
      for (i = 0; i < 11; i++)
      {
        digitalWrite(led[i], LOW);
      }
    }
    else
    {
      for (i = 0; i < input; i++)
      {
        digitalWrite(led[i], HIGH);
        delay(4);
      }
      for (i = i; i < 11; i++)
      {
        digitalWrite(led[i], LOW);
      }
    }
  }
}
