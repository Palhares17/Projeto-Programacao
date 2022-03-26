#include "header.h"
#define tam 100

/* structs */
typedef struct {
    int escolhaPlano;    /* vetor para guardar plano */
    char nome[30];       /* salva o nome da pessoa, em cada linha */
    char plano[30];      /* salva testo dos planos */
    char telefone[30];   /* telefone de matrícula */
    char sexo[30];       /* Sexo na matrícula */
    int idade;           /* idade do cliente na matrícula */
    double peso;         /* peso do cliente na matrícula */
    double altura;       /* altura do cliente na matrícula */
    int numMatricula;    /* Numero teclado */
    char exercicio[200]; /* Os exercícios que vão ser gerados */
} dados;

/* inicio - Funções */
void escolherPlano(dados *cliente, int indice) {
    printf("\n### Agora escolha os nossos planos: ### \n\n");

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
    printf(">>");
    scanf("%d", &cliente[indice].escolhaPlano);

    switch(cliente[indice].escolhaPlano) {
        case 1:
            strcpy(cliente[indice].plano, "Premium");
            break;
        case 2:
            strcpy(cliente[indice].plano, "Platinum");
            break;
        case 3:
            strcpy(cliente[indice].plano, "Bronzeum");
            break;
        case 4:
            strcpy(cliente[indice].plano, "Lataum");
            break;
    }

    printf("Perfeito, terminanos a sua matricula.\n");
    cliente[indice].numMatricula = indice + 100;
    printf("Entao %s, sua matricula eh %d e seu plano eh %s\n", cliente[indice].nome, cliente[indice].numMatricula, cliente[indice].plano);
    printf("\n");
}

void fazerMatricula(dados *cliente, int indice) {
    printf("Bem-vindo!\n");

    printf("Para continuarmos a matricula, Diga seu nome:");
    scanf(" %[^\n]s", cliente[indice].nome);

    printf("Digite sua idade:");
    scanf("%d", &cliente[indice].idade);

    printf("Digite seu peso (kg):");
    scanf("%lf", &cliente[indice].peso);

    printf("Digite sua altura (m):");
    scanf("%lf", &cliente[indice].altura);

    printf("Qual o seu sexo:");
    scanf(" %[^\n]s", cliente[indice].sexo);

    printf("Digite seu telefone:");
    scanf(" %[^\n]s", cliente[indice].telefone);

    escolherPlano(cliente, indice);
}

void buscarMatricula(dados *cliente, int indice) {
    char nomeTeclado[30];

    printf("Para acharmos sua matricula, me diga qual o seu nome:");
    scanf(" %[^\n]s", nomeTeclado);
    for(int i=0; i<indice; i++) {
        if(strcmp(cliente[i].nome, nomeTeclado) == 0) {
            printf("Sua matricula eh:");
            printf("%d", cliente[i].numMatricula);
        }
    }
}

/* função de criação de exercício */
void exercicio(dados *cliente, int indice) {
    int matriculaTeclado;
    int objetivo;
    printf("Para iniciarmos a criação de exercicio\n");
    printf("Qual e a sua matricula:\n");
    printf(">>");
    scanf("%d", &matriculaTeclado);

    printf("Qual e o seu objetivo na academia?\n");
    printf("1) Ficar grandao\n2) Apenas por saúde\n3) So quer pegar mulher.");
    printf(">>");
    scanf("%d", &objetivo);

}

void excluirMatricula(dados *cliente, int indice) {
    int excluirMatricula;
    printf("Excluir qual matricula?");
    printf(">>");
    scanf("%d", &excluirMatricula);

    for(int i=0; i<indice; i++) {
        if(excluirMatricula == cliente[indice].numMatricula) {
            cliente[indice].numMatricula = 0;
        }
    }
}

void print(dados *cliente, int indice) {
    for(int i=0; i<indice; i++) {
        printf("O nome da pessoa [%d] -> %s\n", i, cliente[i].nome);
        printf("A idade da pessoa [%d] -> %d\n", i, cliente[i].idade);
        printf("O peso da pessoa [%d] -> %.2lf\n", i, cliente[i].peso);
        printf("A altura da pessoa [%d] -> %.2lf\n", i, cliente[i].altura);
        printf("O sexo da pessoa [%d] -> %s\n", i, cliente[i].sexo);
        printf("O telefone da pessoa [%d] -> %s\n", i, cliente[i].telefone);
        printf("A matricula da pessoa [%d] -> %d\n", i, cliente[i].numMatricula);
    }
}
/* final - Funções */

int main() {
    dados cliente[tam];

    int i = 0;
    int menu;

    while(1) {
        printf("\nSou atendente virtual.\n\n");
        printf("########## Menu ##########\n");
        printf("Fazer matricula: (1)\n");
        printf("Ver matricula: (2)\n");
        printf("Criar exercicio: (3)\n");
        printf("excluir matricula: (4)\n");
        printf("Sair da atendente virtual: (5)\n\n");

        printf(">>");
        scanf("%d", &menu);

        if(menu == 1) {
            fazerMatricula(cliente, i);
        }

        if(menu == 2) {
            buscarMatricula(cliente, i);
        }

        if(menu == 3) {
            exercicio(cliente, i);
        }

        if(menu == 4) {
            excluirMatricula(cliente, i);
        }

        if(menu == 5) {
            break;
        }

        /* Apenas uma função para mostrar os dados */
        if(menu == 6) {
            print(cliente, i);
        }

        i++;
    }

    return 0;
}