#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tam 5

int main(){
    int escolhaPlano[tam]; /* vetor para guardar plano */
    char plano[tam]; /* salva testo dos planos */
    char nome[tam][30]; /* salva o nome da pessoa, em cada linha */
    int i = 0; /* o indice serve para mapear as pessoas matrículadas na academia */
    int numMatricula[tam]; /* salva o número da matrícula */
    char verNome[30]; /* ver qual o nome da pessoa para ler qual matricula */
    double dinheiroEmCaixa=0;

    int menu = 0;

    while(1) {
        printf("Sou atendente virtual.\n");
        printf("########## Menu ##########\n");
        printf("Fazer matricula: (1)\n");
        printf("Ver matricula: (2)\n");
        printf("Criar exercicio: (3)\n");
        printf("excluir matricula: (4)\n");

        /* matrícula */
        if(menu == 1) {
            scanf("%d", &menu);

            printf("Bem-vindo!\n");

            printf("Para continuarmos a matricula, Diga seu nome:");
            scanf("%s", nome[i]);

            printf("\n");

            printf("Agora escolha os nossos planos: ");

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
            printf("Entao %s, sua matricula eh %d e seu plano eh %s\n", nome[i], numMatricula[i], plano);
            printf("\n");
        }
        if(menu == 2) {
            printf("Voce selecionou ver a matricula!\n");
            printf("Qual o seu nome?");
            scanf("%s", verNome);

            if(strcmp(verNome, nome[i]) == 0) {
                printf("A sua matricula eh %d", numMatricula[i]);
            }
        }
        if(menu == 3) {
            printf("Voce selecionou para criar treino.");

        }

        i++;
    }
}

