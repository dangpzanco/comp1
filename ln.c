
/*****************************************************************/
/*  Computacao Cientifica - EEL 7021
/*  Grupo 11A
/*         Daniel Gomes de Pinho Zanco         Matricula: 13100574
/*         Mateo Daniel Roig Greidanus         Matricula: 13100601
/*         T2
/*****************************************************************/


#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//Input Máximo: n = 32570

double logn(double, int);

int main(int argc, char const *argv[])
{
	int n;
	double x, y1, y2;

	printf("Calculadora de ln(x):\n");

	printf("Insira um x maior que 0.5: ");
	scanf("%lf", &x);

	printf("Insira o numero de termos da serie: ");
	scanf("%d", &n);

	y1 = logn(x, n);
	y2 = log(x);

	printf("Funcao desenvolvida pelo aluno: ln(x) = %lf\n\nFuncao da biblioteca math.h: ln(x) = %lf \n\n", y1, y2);
	system("pause");
	return 0;
}

double logn(double x, int n)
{
	if (x < 0.5) return -1; // Erro
	else
	{
		if (n == 0)	return 0;
		else return pow((x - 1)/x, n)/n + logn(x, n - 1);
	}
}
