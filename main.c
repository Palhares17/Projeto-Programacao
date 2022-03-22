#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tam 5

/* Struct para criação de matrícula */
typedef struct {
    int escolhaPlano; /* vetor para guardar plano */
    char nome[30]; /* salva o nome da pessoa, em cada linha */
    char plano[30]; /* salva testo dos planos */
    char telefone; /* telefone de matrícula */
    char sexo; /* Sexo na matrícula */
    int idade; /* idade do cliente na matrícula */
    double peso; /* peso do cliente na matrícula */
    double altura; /* altura do cliente na matrícula */
    int numMatricula; /* Numero teclado */
} cliente;

int main() {
    cliente cliente[tam];
    int i = 0; /* o indice serve para mapear as pessoas matrículadas na academia */

    /* informações do teclado */
    char nomeTeclado[30]; /* ver qual o nome da pessoa para ler qual matricula */
    int matriculaTeclado; /* Procura de matricula */
    int menu = 0;

    while(1) {
        printf("Sou atendente virtual.\n");
        printf("########## Menu ##########\n");
        printf("Fazer matricula: (1)\n");
        printf("Ver matricula: (2)\n");
        printf("Criar exercicio: (3)\n");
        printf("excluir matricula: (4)\n");

        printf("->");
        scanf("%d", &menu);

        /* matrícula */
        if(menu == 1) {

            printf("Bem-vindo!\n");

            printf("Para continuarmos a matricula, Diga seu nome:");
            scanf("%s", cliente[i].nome);

            printf("Digite sua idade:");
            scanf("%d", &cliente[i].idade);

            printf("Digite seu peso:");
            scanf("%lf", &cliente[i].peso);

            printf("Digite sua altura:");
            scanf("%lf", &cliente[i].altura);

            printf("Qual o seu sexo:");
            scanf("%s", cliente[i].sexo);

            printf("Digite seu telefone:");
            scanf("%s", cliente[i].telefone);

            printf("\n");

            printf("Agora escolha os nossos planos: ");

            printf("\n");

            printf("Nossos planos sao: \n");
            printf("1- Premium:\n- Pode ir todo dia e todos os horarios.\n- Personal para ajudar seu desenvolvimento fisico.\n- Voce tem direito a comer avontede na cantina da academia.\n- Entre outras regalias.\nPOR APENAS (R$ 390,00)\n");

            printf("\n");

            printf("2- Platinum:\n- Pode ir das 6:00 as 20:00 .\n- Personal para ajudar seu desenvolvimento fisico).\n- Entre outras regalias.\nPOR APENAS (R$ 200,00)\n");

            printf("\n");

            printf("3- Bronzeum: \n- Pode ir apenas 12:00 as 20:00 .\n- Sem personal para ajudar seu desenvolvimento fisico).\nPOR APENAS (R$ 100,00)\n ");

            printf("\n");

            printf("4- Lataum: \n-Tem direito a apenas ir a academia das 8:00 as 15:00.\n POR APENAS (R$ 90,00)\n ");

            printf("\n");

            printf("Escolha o seu plano para terminarmos a matricula.\n");
            scanf("%d", &cliente[i].escolhaPlano);

            switch(cliente[i].escolhaPlano) {
                    case 1:
                        strcpy(cliente[i].plano, "Premium");
                        break;
                    case 2:
                        strcpy(cliente[i].plano, "Platinum");
                        break;
                    case 3:
                        strcpy(cliente[i].plano, "Bronzeum");
                        break;
                    case 4:
                        strcpy(cliente[i].plano, "Lataum");
                        break;
            }

            printf("Perfeito, terminanos a sua matricula.\n");
            cliente[i].numMatricula = i;
            printf("Entao %s, sua matricula eh %d e seu plano eh %s\n", cliente[i].nome, cliente[i].numMatricula, cliente[i].plano);
            printf("\n");
        }

        /* Pesquisar nome */
        if(menu == 2) {
            printf("Voce selecionou ver a matricula!\n");
            printf("Qual o seu nome?");
            scanf("%s", nomeTeclado);

            for(int j=0; j<tam; j=0) {
                if(strcmp(nomeTeclado, cliente[i].nome) == 0) {
                    printf("A sua matricula eh %d", cliente[i].numMatricula);
                }
            }
        }

        /* Criar treino */
        if(menu == 3) {
            printf("Voce selecionou para criar treino.");

            printf("Primeiro, me informe a sua matricula.");

        }

        i++;
    }
}

