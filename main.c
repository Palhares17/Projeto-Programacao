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
void matriculaArquivo(dados *cliente, int indice) {
    FILE *matricula;
    matricula = fopen("./arquivos/matricula.txt", "a");

    if(matricula == NULL) {
        printf("ERRO AO ABRIR ARQUIVO MATRICULA");
        return;
    }

    fprintf(matricula, "Nome:%s; Idade:%d; Peso:%.2lf; Altura:%.2lf; Sexo:%s; Telefone:%s; Plano:%s; NumeroMatricula:%d;\n", cliente[indice].nome, cliente[indice].idade, cliente[indice].peso, cliente[indice].altura, cliente[indice].sexo, cliente[indice].telefone, cliente[indice].plano, cliente[indice].numMatricula);

    fclose(matricula);
}

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

    matriculaArquivo(cliente, indice);

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

    /* função com o obetivo de escolher plano */
    escolherPlano(cliente, indice);
}

/* função que busca matricula, usando o nome como motor de pesquisa */
void buscarMatricula(dados *cliente, int indice) {
    char nomeTeclado[30];

    printf("Para acharmos sua matricula, me diga qual o seu nome:");
    scanf(" %[^\n]s", nomeTeclado);
    for(int i=0; i<indice; i++) {
        if(strcmp(cliente[i].nome, nomeTeclado) == 0) {
            printf("SUA MATRICULA EH -> ");
            printf("%d", cliente[i].numMatricula);
        }
    }
}

/* função de criação de exercício */
void exercicio(dados *cliente, int indice) {
    FILE *exercicio;
    exercicio = fopen("./arquivos/exercicio.txt", "a");

    if(exercicio == NULL) {
        printf("ERRO AO ABRIR ARQUIVO EXERCICIO");
        return;
    }

    int matriculaTeclado;
    int objetivo;
    printf("Para iniciarmos a criacao de exercicio\n");
    printf("Qual e a sua matricula:\n");
    printf(">>");
    scanf("%d", &matriculaTeclado);

    printf("Qual e o seu objetivo na academia?\n");
    printf("1) Ficar grandao\n2) Apenas por saude\n3) So fala que faz acadamia.\n");
    printf(">>");
    scanf("%d", &objetivo);

    /* laço de repetição para achar o numero do cliente, assim botar o nome no arquivo exercicio */
    for(int i=0; i<indice; i++) {
        if(matriculaTeclado == cliente[i].numMatricula) {
            if (objetivo == 1) {
                fprintf(exercicio, "%s: 3 series de pule-chinelo |  3 series de agachamento | 3 series de supino no peso que aguentar | 3 series de biceps e triceps que prefirir\n", cliente[i].nome);
            }
            if (objetivo == 2) {
                fprintf(exercicio, "%s: 2 series de pule-chinelo |  2 series de agachamento | corra por 1hora na esteira | 3 series de biceps e triceps que prefirir\n", cliente[i].nome);
            }
            if (objetivo == 3) {
                fprintf(exercicio, "%s: 2 series de pule-chinelo |  2 series de agachamento | 20min de esteira | andar por 20min na esteira\n", cliente[i].nome);
            }
        }
    }
    printf("Os exercicios estao no arquivo de exercicio.txt\n");
    fclose(exercicio);
}

/* função que exclui a matricula */
void excluirMatricula(dados *cliente, int indice) {
    int excluirMatricula;
    printf("Excluir qual matricula?\n");
    printf(">>");
    scanf("%d", &excluirMatricula);

    for(int i=0; i<indice; i++) {
        if(excluirMatricula == cliente[i].numMatricula) {
            cliente[indice].numMatricula = 0;
        }
    }
}

/* Função de print só para verificar se tá tudo certo */
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
            i++; /* o indice só vai crescer se eu criar mais matriculas */
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

    }

    return 0;
}
