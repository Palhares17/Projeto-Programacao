#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"
#define tam 10

int main(){
    int escolhaPlano[tam]; /* vetor para guardar plano */
    char plano[tam]; /* salva testo dos planos */
    int i = 0;
    int numMatricula[tam]; /* salva o número da matrícula */
    double dinheiroEmCaixa=0;

    int menu;
    printf("Sou atendente virtual.\n");
    printf("########## Menu ##########\n");
    printf("Fazer matricula: (1-sim | 2-nao)\n");
    scanf("%d", &menu);

    if(menu==1) {
        while(1) {
            printf("Bem-vindo!\n");

            printf("Para continuarmos a matriculo escolha os nossos planos.\n");

            printf("\n");

            printf("Nossos planos sao: \n");
            printf("1- Premiun:\n- Pode ir todo dia e todos os horarios.\n- Personal para ajudar seu desenvolvimento fisico.\n- Voce tem direito a comer avontede na cantina da academia.\n- Entre outras regalias.\nPOR APENAS (R$ 390,00)\n");

            printf("\n");

            printf("2- Platinum:\n- Pode ir das 6:00 as 20:00 .\n- Personal para ajudar seu desenvolvimento fisico).\n- Entre outras regalias.\nPOR APENAS (R$ 200,00)\n");

            printf("\n");

            printf("3- Bronzeum: \n- Pode ir apenas 12:00 as 20:00 .\n- Sem personal para ajudar seu desenvolvimento fisico).\nPOR APENAS (R$ 100,00)\n ");

            printf("\n");

            printf("4- Lataum: \n-Tem direito a apenas ir a academia das 8:00 as 15:00.\n POR APENAS (R$ 90,00)\n ");

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
            numMatricula[i] = i;
            printf("Sua matricula eh %d e seu plano eh %s\n", numMatricula[i], plano);
            printf("\n");

            i++;
        }
    }
}

