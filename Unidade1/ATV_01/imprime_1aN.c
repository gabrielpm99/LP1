#include <stdio.h>

int imprimirNumeros(int N) {
    // Imprime de 1 a N;
    for(int i = 1; i <= N; i++) {
        printf("%i \n", i);
    }
}

int main() {
    int N;
    printf("Digite um numero inteiro positivo: ");
    scanf("%i", &N);

    if(N > 0) {
        imprimirNumeros(N);
    } else {
        printf("O numero digitado eh invalido");
    }

    return 0;
}
