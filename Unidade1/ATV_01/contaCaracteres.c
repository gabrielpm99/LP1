#include <stdio.h>
#include <string.h>

int contarCaracteres(char *string) {
    int total = 0;
    int i = 0;
    
    // Checa cada caracter e para quando for igual ao fim da string.
    while(string[i] != '\0') {
        total++;
        i++;
    }

    return total;
}

int main() {
    int tam = 300;
    char string[tam];

    printf("Digite a string: ");
    
    // Lê a string integralmente
    fgets(string, sizeof(string), stdin);
    // Retira a quebra de linha no final da string
    string[strcspn(string, "\n")] = 0;

    int qtdCaracteres = contarCaracteres(string);

    printf("A string possui %i caracteres", qtdCaracteres);

    return 0;
}
