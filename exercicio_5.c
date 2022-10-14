#include <stdio.h>
#include <stdlib.h>
#include<locale.h>

#define TAMLinha 1
#define TAMColuna 2

struct TVeiculo {
    char Modelo[41];
    float ValorMercado;
    int AnoFabricacao;
};

//Declaracao de variavel global Concessionaria
struct TVeiculo Concessionaria[TAMLinha][TAMColuna];

/* Procedimento que define e exibe as opcoes de menu */
void menuOpcoes()
{
    printf("\n===================== MENU DE OPCOES =====================");
    printf("\n[1] - Cadastrar todos os veiculos                         ");
    printf("\n[2] - Imprimir o total de veiculos vendidos por mes       ");
    printf("\n[3] - Imprimir o total de veiculos vendidos por fabricante");
    printf("\n[4] - Imprimir os veiculos por mes e fabricante           ");
    printf("\n[5] - Imprimir a qtde de veiculos por mes em ano impar    ");
    printf("\n----------------------------------------------------------");
    printf("\n[6] - Sair do programa                                    ");
    printf("\n----------------------------------------------------------");
}

/* Procedimento que realiza o cadastro de todos os
   veiculos vendidos por uma concessionaria
   nos meses de janeiro a maio de 2020 */
void cadastrarVeiculo(int linha, int coluna)
{
    setbuf(stdin, NULL);
    printf("\nDigite o Modelo do veiculo [%d][%d]: ", linha+1, coluna+1);
    gets(Concessionaria[linha][coluna].Modelo);
    printf("\nDigite o Valor de Mercado do veiculo [%d][%d]: ", linha+1, coluna+1);
    scanf("%f", &Concessionaria[linha][coluna].ValorMercado);
    printf("\nDigite o Ano de Fabricao do veiculo [%d][%d]: ", linha+1, coluna+1);
    scanf("%d", &Concessionaria[linha][coluna].AnoFabricacao);
}

/* Função que realiza o calculo do total de veiculos
   vendidos por mes informado pelo usuario */
float calcularTotalVeiculosVendidosPorMes()
{
    //nao implementado
    return 0;
}

//???
float calcularTotalVeiculosVendidosPorFabricante()
{
    //nao implementado
    return 0;
}

/*Procedimento que exibe os dados de um veiculo vendido
  em um determinado mes e fabricante informado pelo usuario */
void imprimirVeiculosPorMesEFabricante(int mes, int fab)
{
    char fabricante[40];

    if (fab == 0)
    {
        strcpy(fabricante, "Chevrolet");
    }
    else if (fab == 1)
    {
        strcpy(fabricante, "Ford");
    }
    else
    {
        strcpy(fabricante, "Fiat");
    }

    printf("\nImprimindo os dados de veiculo fabricado por %s...", fabricante);
    printf("\nModelo do Veiculo: %s", Concessionaria[mes][fab].Modelo);
    printf("\nValor de Mercado.: %.2f", Concessionaria[mes][fab].ValorMercado);
    printf("\nAno de Fabricao: %d", Concessionaria[mes][fab].AnoFabricacao);
}

//???
int quantidadeVeiculosProduzidosPorMesEAno()
{
    //n�o implementado
    return 0;
}

// Procedimento para exibir os meses de venda de veiculos
void tiposMeses()
{
    printf("\n-| Meses de Venda |-");
    printf("\n[1] - Janeiro");
    printf("\n[2] - Fevereiro");
    printf("\n[3] - Marco");
    printf("\n[4] - Abril");
    printf("\n[5] - Maio");
}

// Procedimento para exibir os nomes dos fabricantes de veiculos
void tiposFabricantes()
{
    printf("\n-| Tipos de Fabricantes |-");
    printf("\n[1] - Chevrolet");
    printf("\n[2] - Ford");
    printf("\n[3] - Fiat");
}

//Programa Principal
int main()
{
    int menuOpcao = 0, mes = 0, fab = 0;
    float somaVeiculosVendidosMes = 0;
    int mesDeVenda = 0;
    float somaVeiculosVendidosFabricante = 0;
    int fabricanteDeVenda = 0;

    setlocale(LC_ALL, "Portuguese");

    do {
        system("cls");
        menuOpcoes();
        printf("\nDigite a opcao desejada: ");
        scanf("%d", &menuOpcao);

        //Cadastrar todos os veiculos
        if(menuOpcao == 1)
        {
            system("cls");

            for (int i=0; i<TAMLinha; i++)
            {
                for (int j=0; j<TAMColuna; j++)
                {
                    cadastrarVeiculo(i, j);
                }
            }
        }
        //Imprimir o total de veiculos vendidos por mes
        else if(menuOpcao == 2)
        {

            do {
                system("cls");
                tiposMeses();
                printf("\nInforme o codigo do mes para gerar o total de veiculos vendidos: ");
                scanf("%d", &mesDeVenda);
            } while(mesDeVenda < 1 || mesDeVenda > 5);

            for (int i=0; i<TAMColuna; i++) //fixando a linha
            {
                somaVeiculosVendidosMes =
                    somaVeiculosVendidosMes + Concessionaria[mesDeVenda-1][i].ValorMercado;
            }

            switch (mesDeVenda)
            {
                case 1:
                    printf("\nO total de veiculos vendidos no mes de Janeiro foi de: %.2f",
                           somaVeiculosVendidosMes);
                    break;
                case 2:
                    printf("\nO total de veiculos vendidos no mes de Fevereiro foi de: %.2f",
                           somaVeiculosVendidosMes);
                    break;
                case 3:
                    printf("\nO total de veiculos vendidos no mes de Mar�o foi de: %.2f",
                           somaVeiculosVendidosMes);
                    break;
                case 4:
                    printf("\nO total de veiculos vendidos no mes de Abril foi de: %.2f",
                           somaVeiculosVendidosMes);
                    break;
                case 5:
                    printf("\nO total de veiculos vendidos no mes de Maio foi de: %.2f",
                           somaVeiculosVendidosMes);
                    break;
            }
        }
        //Imprimir o total de veiculos vendidos por fabricante
        else if (menuOpcao == 3)
        {
            do {
                system("cls");
                printf("\nInforme um dos codigos de fabricante abaixo para gerar o "
                       "total de veiculos vendidos\n-> [1] Chevrolet | [2] Ford | [3] Fiat: ");
                scanf("%d", &fabricanteDeVenda);
            } while(fabricanteDeVenda < 1 || fabricanteDeVenda > 3);

            for (int i=0; i<TAMLinha; i++) //fixando a coluna
            {
                somaVeiculosVendidosFabricante =
                    somaVeiculosVendidosFabricante + Concessionaria[i][fabricanteDeVenda-1].ValorMercado;
            }

            switch (fabricanteDeVenda)
            {
                case 1:
                    printf("\n O total de veiculos vendidos do fabricante Chevrolet foi de: %.2f",
                           somaVeiculosVendidosFabricante);
                    break;
                case 2:
                    printf("\n O total de veiculos vendidos do fabricante Ford foi de: %.2f",
                           somaVeiculosVendidosFabricante);
                    break;
                case 3:
                    printf("\n O total de veiculos vendidos do fabricante Fiat foi de: %.2f",
                           somaVeiculosVendidosFabricante);
                    break;
            }
            system("pause");
        }
        //Imprimir os veiculos por mes e fabricante
        else if (menuOpcao == 4)
        {
            tiposMeses();
            printf("\nDigite o mes de venda: ");
            scanf("%d", &mes);

            tiposFabricantes();
            printf("\nDigite o nome do fabricante: ");
            scanf("%d", &fab);

            imprimirVeiculosPorMesEFabricante(mes-1, fab-1);
        }
        //Imprimir a qtde de veeculos por mes em ano impar
        else if (menuOpcao == 6)
        {

        }
        system("pause");
    } while(menuOpcao != 6);

    printf("\nPrograma finalizado com sucesso!");
    return 0;
}
