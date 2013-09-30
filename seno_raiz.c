/*******************************************************************************************/
/*  Computacao Cientifica - EEL 7021
/*  Grupo 11A
/*         Daniel Gomes de Pinho Zanco         Matricula: 13100574
/*         Mateo Daniel Roig Greidanus         Matricula: 13100601
/*         T3
/*	Compilado e testado no Code::Blocks
/*  Pode ser conferido no site: https://github.com/dangpzanco/comp1/blob/master/seno_raiz.c
/*******************************************************************************************/

// Inclúi as bibliotecas necessárias
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Declaração das funções utilizadas
int fator(int);
double raiz(double x);
double seno(double, int);

int main()
{
	printf("Calculadora do seno de um angulo em graus (favor ler comentarios da funcao no codigo)\n\n");

	// Declaração de variáveis: x = input, y = output do aluno, z = output do math.h e n = número de interações
	double x, y, z, n;

	printf("Insira o angulo em graus que deseja calcular o seno: ");

	// Atribui o valor desejado ao input
	scanf("%lf", &x);

	printf("\nInsira o numero de interacoes que deseja para calcular o seno: ");

	// Atribui o valor desejado ao número de interações
	scanf("%d", &n);

	// Atribuição de valores às variáveis de output com conversão de graus para radianos
	y = seno(x * 3.14159265358979323846 / 180, n);
	z = sin(x * 3.14159265358979323846 / 180);

	// Exibição dos resultados na tela
	printf("\nFuncao do aluno: %lf\n", y);
	printf("Funcao do <math.h>: %lf\n", z);

	printf("Calculadora de raiz quadrada (retorna -1 se inserido um numero menor que 0)\n");
	printf("\nInsira o numero que deseja calcular a raiz quadrada: ");

	// Atribui um novo valor ao input
	scanf("%lf", &x);

	// Atribuição de novos valores às variáveis de output
	y = raiz(x);
	z = sqrt(x);

	// Exibição dos resultados na tela
	printf("\nFuncao do aluno: %lf \n", y);
	printf("Funcao do <math.h>: %lf \n", z);

	// Pausa na execução e retorno de 0 para sinalizar sucesso na execução
	system("pause");
	return 0;
}

// As funções fatorial (fator) é criada para a utilização na função seno
int fator(int n)
{
	if (n > 0) return n*fator(n - 1);
	else return 1;
}

// Utiliza uma série de Taylor para o cálculo do seno de x, com x em radianos.
// Por algum motivo a função está retornando o arcosseno do seno do angulo "x",
// por exemplo: com x = 30 graus, o seno de x é igual a 0.5 e arcosseno(0.5 radianos) = 0.523599,
// a função desenvolvida retorna 0.523599 neste caso, apesar de utilizar a série de Taylor correta, conforme a fonte.
// Essa função utiliza da recursividade como principal recurso, assim como a função fatorial,
// formando uma série que vai até onde o usuário necessitar.
// Fonte: https://pt.wikipedia.org/wiki/Seno
double seno(double x, int n)
{
	if (n >= 0) return (pow(-1.0, n)*pow(x, 2.0*n + 1.0))/fator(2.0*n + 1.0) + seno(x, n - 1.0);
	else return 0.0;
}

// Implementação da função raiz quadrada utilizando um inline assembly code.
// Retorna -1 se inserido um numero menor que 0.
// O comando asm chama a instrução x87 "fsqrt" (floating square root),
// tomando "x" como input e atribuindo o valor de output ao "resultado",
// esse tipo de comando torna o código mais rápido e confiável, pois
// utiliza de uma instrução nativa do processador Intel, e não de uma série infinita.
double raiz(double x)
{
  if (x < 0.0) return 1;
  else
    {
      double resultado;
      asm ("fsqrt" : "=t" (resultado) : "0" (x));
      return resultado;
    }
}
