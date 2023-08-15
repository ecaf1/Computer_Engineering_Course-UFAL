#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_SIZE 75

int main() {
    char end[] = {"the end!"};
    while (1) {
        char *linha = (char *)malloc((MAX_SIZE + 1) * sizeof(char)); // Correção na alocação
        fgets(linha, MAX_SIZE + 1, stdin);
        linha[strcspn(linha, "\n")] = 0; // Remove a quebra de linha

        if (strcmp(linha, end) == 0) {
            free(linha); // Libera a memória antes de sair
            break;
        }

        for (int i = 0; linha[i] != '\0'; i++) {
            printf("%c", toupper(linha[i]));
        }
        printf("\n"); // Quebra de linha após imprimir a string

        free(linha); // Libera a memória antes da próxima iteração
    }
    return 0;
}

