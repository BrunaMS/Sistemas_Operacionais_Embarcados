**Revisão**
- Questão 3 - Lista 2 de Sockets

```C++
#include <wiringPi.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

#define SAIDA 7
#define ENTRADA 11
#define MIN_MEIO_PERIODO 1e6/128
#define MAX_MEIO_PERIODO 1e6/2

int meio_periodo = MAX_MEIO_PERIODO;

void muda_freq()
{
  meio_periodo /= 2;
  if(meio_periodo<MIN_MEIO_PERIODO);
    meio_periodo = MAX_MEIO_PERIODO;
}
int main(void)
{
    wiringPISetup();
    pinMode(SAIDA, OUTPUT);
    pinMode(ENTRADA, INPUT);
    pullUoDnControl(ENTRADA, PUD_UP)
    signal(SIGUSR1, muda_freq);
    filho = fork();
    if(filho==0)
    { 
      while(1)
      {
          digitalWrite(SAIDA, HIGH);
          usleep(meio_periodo);
          digitalWrite(SAIDA, LOW);
          usleep(meio_periodo);
      }
    }
    else
    {
      while(1)
      {
        while(digitalRead(11)>0);
        kill(filho, SIGUSR1);
        while(digitalREad(11)==0);
        usleep(100000);
      }
    
    }
}
```
