#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define TAMANHO_MAXIMO 100
#define PI 3.14159265;

double retpol(double [2][2]);
double soma(double [2][2]);
double multi(double [2][2]);
double divisao(double [2][2]);
double sub(double [2][2]);

int main(int argc, char const *argv[])
{
	int n, m, k;
	double N[2][2] = {{0, 0}, {0, 0}};
	double R[2] = {0, 0};

	printf("Deseja trabalhar na forma retangular (1) ou polar (2)?\n");
	scanf("%i", &n);

	printf("\nDeseja realizar qual operacao?\n\n");
	printf("1: Soma (X+Y)\n");
    printf("2: Subtracao (X-Y)\n");
    printf("3: Multiplicacao (X*Y)\n");
    printf("4: Divisao (X/Y)\n");
    printf("5: Divisao (Y/X)\n");
    scanf("%i", &m);

	if (n == 1)
	{
		printf("Insira o primeiro numero na forma X = a + bi:\n");
		printf("a = ");
		scanf("%lf", &N[0][0]);
		printf("\nb = ");
		scanf("%lf", &N[0][1]);
		printf("\n\nInsira o segundo numero na forma Y = c + di:\n");
		printf("c = ");
		scanf("%lf", &N[1][0]);
		printf("\nd = ");
		scanf("%lf", &N[1][1]);

		switch (m)
		{
			case 1: //soma
				R[0] = N[0][0] + N[1][0];
				R[1] = N[0][1] + N[1][1];
				printf("\nA soma X + Y = %lf + (%lf)i\n", R[0], R[1]);
				break;
			case 2: //subtracao
				R[0] = N[0][0] - N[1][0];
				R[1] = N[0][1] - N[1][1];
				printf("\nA subtracao X - Y = %lf + (%lf)i\n", R[0], R[1]);
				break;
			case 3: //multiplicacao
				R[0] = N[0][0]*N[1][0] - N[0][1]*N[1][1];
				R[1] = N[0][0]*N[1][1] + N[0][1]*N[1][0];
				printf("\nA multiplicacao X*Y = %lf + (%lf)i\n", R[0], R[1]);
				break;
			case 4:// divisao X/Y
				R[0] = (N[0][0]*N[1][0] + N[0][1]*N[1][1])/(N[1][0]*N[1][0] + N[1][1]*N[1][1]);
				R[1] = (N[0][1]*N[1][0] - N[0][0]*N[1][1])/(N[1][0]*N[1][0] + N[1][1]*N[1][1]);
				printf("\nA divisao X/Y = %lf + (%lf)i\n", R[0], R[1]);
				break;
			case 5:// divisao Y/X
				R[0] = (N[0][0]*N[1][0] + N[0][1]*N[1][1])/(N[0][0]*N[0][0] + N[0][1]*N[0][1]);
				R[1] = (N[0][0]*N[1][1] - N[0][1]*N[1][0])/(N[0][0]*N[0][0] + N[0][1]*N[0][1]);
				printf("\nA divisao Y/X = %lf + (%lf)i\n", R[0], R[1]);
				break;

		}
	}
	else
	{
		printf("Insira o primeiro numero na forma X = |X|*(cos(a) + i*sin(a))\n");
		printf("|X| = ");
		scanf("%lf", &N[0][0]);
		printf("\na = ");
		scanf("%lf", &N[0][1]);
		printf("\n\nInsira o segundo numero na forma Y = |Y|*(cos(b) + i*sin(b)):\n");
		printf("|Y| = ");
		scanf("%lf", &N[1][0]);
		printf("\nb = ");
		scanf("%lf", &N[1][1]);

		switch (m)
		{
			case 1:

		}
	}

	system("pause");
	return 0;
}
