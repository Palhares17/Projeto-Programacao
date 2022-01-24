#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tam 10

int main(){
    int decisao;
    int escolhaPlano[tam];
    char plano[tam];
    int certeza;
    int i = 0;
    int numMatricula[tam];
    double dinheiroEmCaixa;

    int menu;

    while(1) {
        printf("Bem-vindo!\n");
        printf("Gostaria de fazer matricula ?\n");
        printf("1- Sim / 2- Nao\n");
        scanf("%d", &decisao);

        if(decisao == 2) {
            printf("Voce nao quer se matricular. Tem certeza?\n");
            printf("1- Sim / 2- Nao\n");
            scanf("%d", &certeza);

            if(certeza == 2){
                printf("Tudo bem, ate a proxima.\n");
                break;
            } else {
                printf("Que bom, vai continuar com a gente!!!\n");
            }
         } else {
            printf("Para continuarmos a matriculo escolha os nossos planos.\n");

            printf("\n");

            printf("Nossos planos sao: \n");
            printf("1- Premiun:\n- Pode ir todo dia e todos os horarios.\n- Personal para ajudar seu desenvolvimento fisico.\n- Voce tem direito a comer avontede na cantina da academia.\n- Entre outras regalias.\nPOR APENAS (R$ 390,00\n");

            printf("\n");

            printf("2- Platinum:\n- Pode ir das 6:00 as 20:00 .\n- Personal para ajudar seu desenvolvimento fisico.\n- Entre outras regalias.\nPOR APENAS (R$ 200,00\n");

            printf("\n");

            printf("3- Bronzeum: \n- Pode ir apenas 12:00 as 20:00 .\n- Sem personal para ajudar seu desenvolvimento fisico.\nPOR APENAS (R$ 100,00\n ");

            printf("\n");

            printf("4- Lataum: \n-Tem direito a apenas ir a academia das 8:00 as 15:00.\n POR APENAS (R$ 90,00\n ");

            printf("\n");

            printf("Escolha o seu plano para terminarmos a matricula.\n");
            scanf("%d", &escolhaPlano[i]);

            switch(escolhaPlano[i]) {
                case 1:
                    strcpy(plano, "Premium");
                    dinheiroEmCaixa += 390.00;
                    break;
                case 2:
                    strcpy(plano, "Platinum");
                    dinheiroEmCaixa += 200.00;
                    break;
                case 3:
                    strcpy(plano, "Bronzeum");
                    dinheiroEmCaixa += 100.00;
                    break;
                case 4:
                    strcpy(plano, "Lataum");
                    dinheiroEmCaixa += 90.00;
                    break;
            }

            printf("Perfeito, terminanos a sua matricula.\n");
            numMatricula[i] = i*tam;

            printf("Sua matricula eh %d e seu plano eh %s", numMatricula[i], plano);
        }
        i++;
    }

    printf("O dinheiro em caixa eh de %2f", dinheiroEmCaixa);
}