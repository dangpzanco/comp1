#include <stdio.h>
#include <stdlib.h>

struct equipamento {
	char descricao[40];
	int quantidade;
	float potencia;
	float horas;
	int dias;
	float consumo;
};

struct equipamento eqs[30];
struct equipamento temp;

int main()
{
	int a, n, c, d;
    float CustoTotal;
    float ConsumoTotal = 0;

	printf("Quantos equipamentos? (No maximo 30!!!)\n");
	scanf("%i", &n);

	for(a = 0; a < n; a++)
    {
            printf("Insira as informacoes do Equipamento #%i:\n\n", a + 1);
            printf("Descricao:\n");
            scanf("%s", &eqs[a].descricao);
            printf("Quantidade deste tipo de Eq.:\n");
            scanf("%i", &eqs[a].quantidade);
            printf("Potencia (em W):\n");
            scanf("%f", &eqs[a].potencia);
            printf("Horas ligado por dia:\n");
            scanf("%f", &eqs[a].horas);
            printf("Dias ligado por mes:\n");
            scanf("%i", &eqs[a].dias);
            eqs[a].consumo = (eqs[a].quantidade * eqs[a].horas * eqs[a].dias * eqs[a].potencia)/1000.0;
            ConsumoTotal += eqs[a].consumo;
    }

    CustoTotal = ConsumoTotal*0.35;

    for (c = 0 ; c < n - 1; c++)
    {
        for (d = 0 ; d < n - c - 1; d++)
        {
            if (eqs[d].consumo < eqs[d+1].consumo)
            {
                temp = eqs[d];
                eqs[d] = eqs[d+1];
                eqs[d+1] = temp;
            }
        }
    }
    
    printf("\n Lista dos equipamentos inseridos:\n");
    for (c = 0; c < n; c++) printf("%s --- %f KWh \n", eqs[c].descricao, eqs[c].consumo);
    printf("Valor estimado para o mes: %f Reais\n", CustoTotal);
    system("pause");
    return 0;
}
