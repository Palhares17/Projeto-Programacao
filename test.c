#include <stdio.h>

void string(char *name) {
    printf("Nome:");
    scanf(" %[^\n]s", name);
}

void print(char *name) {
    printf("%s", name);
}

int main() {
    char nome[30];

    string(nome);
    print(nome);
    return 0;
}