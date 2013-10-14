/************************************************************************************/
/*  Computacao Cientifica - EEL 7021
/*  Grupo 11A
/*         Daniel Gomes de Pinho Zanco         Matricula: 13100574
/*         Mateo Daniel Roig Greidanus         Matricula: 13100601
/*         T4
/*	Compilado e testado com Code::Blocks 12.11
/*  Pode ser conferido no site: https://github.com/dangpzanco/comp1/blob/master/matriz_losango.c
/***********************************************************************************************/

// Inclúi as bibliotecas necessárias
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int i, j, n, M[20][20]; // funciona para qualquer M[n][n] com n < int máximo e ímpar

	printf("Insira um numero impar n (3 < n < 20) para formar a figura em uma matriz n por n: ");
	scanf("%i", &n);
	printf("\n");

// zera tudo, retirando numeros residuais da memoria
	for (i = 0; i < n; ++i)
		for (j = 0; j < n; ++j)
			M[i][j] = 0;

// preenche uma piramide na parte superior, deixando resíduos (1s) embaixo.
	for (i = 0; i < n/2; i++)
		for (j = 0; j < n/2; j++)
		{
            M[i + j][n/2 - i] = 1;
            M[i + j][n/2 + i] = 1;
		}

//espelha o desenho de cima para baixo, anulando os resíduos do loop 2,
//também desenha o traçado central (é como um grande sinal de "-")
	for (i = n/2; i < n; i++)
		for (j = 0; j < n; j++)
		{
            M[i][j] = M[n - i - 1][j]; // espelho
            M[n/2][j] = 1; //"--------------"
		}

//exibe a matriz na tela
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
				printf(" %i",M[i][j]);
		printf("\n");
	}
	system("PAUSE");
	return 0;
}


/*

1. Escreve um programa que gere e armazene em um array (matriz bidimensional) a matriz mostrada
abaixo. Considerações:

#1 O número de linha e colunas são iguais e deve ser um valor impar(3 ≤ n ≤ 20) a ser fornecido pelo
usuário em tempo de execução do programa.

#2 Usar exclusivamente arrays e estruturas de repetição. Procure minimizar o número de instruções.

0 0 1 0 0
0 1 1 1 0
1 1 1 1 1
0 1 1 1 0
0 0 1 0 0

*/
