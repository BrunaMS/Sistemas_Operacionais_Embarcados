#include <wiringPi.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <pcf8591.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define Address 0x48
#define BASE 64
#define A0 BASE+0
#define SAIDA 23
#define MEIO_PERIODO (1e6/2)

float y[40]= {0};
float x[40]= {0};
int flag = 0;

void *respostaPlanta(void *unused);
//void opcoes(int);
int i, escolha;
char string[30];

int main(int argc, char** argv)
{
	sprintf(string,"echo %d > pid.txt",getpid());
	system(string);

	pthread_t thread_id2;
	wiringPiSetup();
	pcf8591Setup(BASE,Address);
	pinMode(SAIDA, OUTPUT);
	//signal(SIGINT, opcoes);
	escolha = atoi(argv[1]);//Receber a planta escolhida

	if(escolha == 5){
		printf("Aplicação finalizada");
		exit(1);
	}
	pthread_create(&thread_id2,NULL, &respostaPlanta, NULL);

	while(1){
		flag = 1;
		digitalWrite(SAIDA, HIGH);
		usleep(MEIO_PERIODO);
		flag = 0;
		digitalWrite(SAIDA, LOW);
		usleep(MEIO_PERIODO);
	}
}

void *respostaPlanta(void *unused){
	while(1)
	{
		for(i = 39;i>0;i--){
			x[i] = x[i-1];
			y[i] = y[i-1];
		}
		usleep(10);
		x[0] = analogRead(A0);
		usleep(10);
		if(flag == 1){
			switch (escolha)
			{
				case 1:
					y[0] = (0.05847*x[1]) + (0.00000001 *x[2])
					+ (1.348*y[1]) - (0.4066*y[2]);
				break;
				case 2:
					y[0] = (0.08035*x[1]) + (0.00000001 *x[2])
					+ (1.738*y[1]) - (0.8187*y[2]);

				break;
				case 3:
					y[0] = (0.08866*x[1]) + (0.00000001 *x[2])
					+ (1.911*y[1]) -y[2];
				break;
				case 4:
					y[0] = (0.06667*x[1]) + (0.00000001 *x[2])
					+ (1.482*y[1]) - (0.5488*y[2]);
				break;
				case 5:
					exit(1);
				default:
					y[0] = x[0];
			}
	} else y[0] = x[0];
		analogWrite(A0,y[0]);
	}
}
/*void opcoes(int sig){
	printf("Sinal Crtl+C(%d) recebido!!\n",sig);
	printf("Deseja alternar a função de transferência? Selecione a nova:\n",sig);
	printf("1)  \n");
	printf("2)  \n");
	printf("3)  \n");
	printf("4)  \n");
	printf("5)Sair do programa\n");
	scanf("%d",&escolha);
	if(escolha == 5){
		printf("Aplicação finalizada");
		exit(1);
	}
}*/
