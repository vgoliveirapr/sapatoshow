#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

/* Minha dupla: Victor Gabriel de Oliveira e Caio Augusto Exteckoetter */

struct calcado{
    int codigo;
    char marca[50];
    int numero;
    int quantidade;
    float valor;
}*calcade;

bool estaCadastrado = false;
int x;


void incluirNovoCalcado(){

    system("cls");

    if(estaCadastrado == false){
        printf("\nQuantos calçados quer incluir? ");
        scanf("%d", &x);

        calcade = (struct calcado *) malloc(x * sizeof(struct calcado));

        for(int i = 0; i < x; i++){

        printf("\n\tProduto");

        printf("\nCódigo: ");
        scanf("%d", &calcade[i].codigo);

        printf("\nMarca: ");
        scanf("%s", calcade[i].marca);

        printf("\nNumeração: ");
        scanf("%d", &calcade[i].numero);

        printf("\nQuantidade: ");
        scanf("%d", &calcade[i].quantidade);

        printf("\nPreço: R$ ");
        scanf("%f", &calcade[i].valor);

    }

    }else{
        int v = 0;
        printf("\nQuantos calçados quer incluir? ");
        scanf("%d", &v);
        int aux = x;
        x += v;

        calcade = (struct calcade *) realloc(calcade, x * sizeof(struct calcado));

        for(int i = aux; i < x; i++){

        printf("\n\tProduto");

        printf("\nCódigo: ");
        scanf("%d", &calcade[i].codigo);

        printf("\nMarca: ");
        scanf("%s", calcade[i].marca);

        printf("\nNumeração: ");
        scanf("%d", &calcade[i].numero);

        printf("\nQuantidade: ");
        scanf("%d", &calcade[i].quantidade);

        printf("\nPreço: R$ ");
        scanf("%f", &calcade[i].valor);

    }

    }

    system("cls");

    printf("\nProduto(s) cadastrado(s) com sucesso!\n");

    estaCadastrado = true;

}

void alterarCalcado(){

    system("cls");

    if(estaCadastrado == true){

        int produtoExiste;
        int alterar;

        printf("Qual o código do produto que quer alterar? ");
        scanf("%d", &produtoExiste);

        for(int i = 0; i < x; i++){
            if(produtoExiste == calcade[i].codigo){

                    printf("\nO que quer alterar? ");
                    printf("\n 1- Código");
                    printf("\n 2- Marca");
                    printf("\n 3- Numeração");
                    printf("\n 4- Quantidade");
                    printf("\n 5- Valor");
                    printf("\n 6- Todos");

                    printf("\nOpção: ");
                    scanf("%d", &alterar);

                    switch(alterar){

                        case 1:
                            printf("\nNovo código: ");
                            scanf("%d", &calcade[i].codigo);
                            break;

                        case 2:
                            printf("\nNova marca: ");
                            scanf("%s", calcade[i].marca);
                            break;

                        case 3:
                            printf("\nNova numeração: ");
                            scanf("%d", &calcade[i].numero);
                            break;

                        case 4:
                            printf("\nNova quantidade: ");
                            scanf("%d", &calcade[i].quantidade);
                            break;

                        case 5:
                            printf("\nNovo valor: R$ ");
                            scanf("%f", &calcade[i].valor);
                            break;

                        case 6:
                            printf("\nNovo código: ");
                            scanf("%d", &calcade[i].codigo);
                            printf("\nNova marca: ");
                            scanf("%s", calcade[i].marca);
                            printf("\nNova numeração: ");
                            scanf("%d", &calcade[i].numero);
                            printf("\nNova quantidade: ");
                            scanf("%d", &calcade[i].quantidade);
                            printf("\nNovo valor: R$ ");
                            scanf("%f", &calcade[i].valor);
                            break;

                    }

                    system("cls");

                    printf("\nProduto alterado com sucesso!\n");

            }else{

                printf("\nCódigo inválido!\n");

            }

        }

    }else{

        printf("\nPrecisa primeiro cadastrar um produto, para assim poder alterar o mesmo!\n");

    }

}

void relatorios(){

    system("cls");

    if(estaCadastrado == true){

        int relat;

        printf("\nQual relatório(s) você quer ver? \n");
        printf("\n1- Relatório por marca\n");
        printf("\n2- Relatório por numeração\n");
        printf("\n3- Relatório por código\n");
        printf("\n4- Todos os relatórios\n");

        printf("\nOpção: ");
        scanf("%d", &relat);
        system("cls");

        switch(relat){

            case 1:
                   printf("\n\tTodas as marcas cadastradas\n");
                for(int i = 0; i < x; i++){
                    printf("\n%s", calcade[i].marca);
                }
                break;

            case 2:
                    printf("\n\tTodas as numerações cadastradas\n");
                for(int i = 0; i < x; i++){
                    printf("\n%d", calcade[i].numero);
                }
                break;

            case 3:
                    printf("\n\tTodas os códigos cadastrados\n");
                for(int i = 0; i < x; i++){
                    printf("\n%d", calcade[i].codigo);
                }
                break;

            case 4:
                    printf("\n\tProdutos cadastrados\n");
                    printf("\nCódigo, Marca, Numeração, Quantidade, Preço");
                for(int i = 0; i < x; i++){
                printf("\n%d       %s     %d       %d     R$ %.2f\n", calcade[i].codigo, calcade[i].marca, calcade[i].numero, calcade[i].quantidade, calcade[i].valor);

            }
            break;

            }

    }else{

        printf("\nNão há produtos cadastrados para gerar relatórios!\n");

    }
}

void excluirCalcado(){

    if(estaCadastrado == true){

        int cod;
        printf("Qual o código do produto a ser excluído? ");
        scanf("%d", &cod);

        for(int i = 0; i < x; i++){
            if(cod == calcade[i].codigo){
                calcade[i] = calcade[x-1];
            }
        }
        x--;
        calcade = (struct calcade*) realloc(calcade, x * sizeof(struct calcado));
        system("cls");
        printf("\nProduto removido!\n");

    }else{

        system("cls");
        printf("\nPrecisa primeiro cadastrar um produto, para assim poder excluir o mesmo!\n");

    }
}

int main()
{

    setlocale(LC_ALL, "Portuguese");

    int opcao = 0;

    while(1){
    printf("\n\tSistema da Sapato Show\n");

    printf("\nOpções:\n");

    printf("\n1 - Incluir novo calçado\n");

    printf("\n2 - Alterar cadastro de um calçado\n");

    printf("\n3 - Relatórios\n");

    printf("\n4 - Excluir um calçado\n");

    printf("\n5 - Sair\n");

    printf("\nOpção: ");
    scanf("%d", &opcao);

        switch(opcao){

            case 1:
                incluirNovoCalcado();
                break;
            case 2:
                alterarCalcado();
                break;
            case 3:
                relatorios();
                break;
            case 4:
                excluirCalcado();
                break;
            case 5:
                free(calcade);
                return 0;

        }
    }
}
