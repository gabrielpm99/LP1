#include <stdio.h>
#include <stdbool.h>

int verificarPrimalidade(int N) {
    int qtdDivisores = 0;

    // Calcula a quantidade de divisores de N
    for(int i = 1; i <= N; i++) {
        if(N % i == 0) {
            qtdDivisores++;
        }
    }

    if(qtdDivisores == 2) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int N;
    printf("Digite um numero inteiro: ");
    scanf("%i", &N);

    // Armazena 1 se for primo e 0 se não for primo
    int ehPrimo = verificarPrimalidade(N);

    if(N > 0) {
        if(ehPrimo) {
            printf("O numero %i eh primo", N);
        } else {
            printf("O numero %i nao eh primo", N);
        }
    } else {
        printf("Numero invalido");
    }

    return 0;
}
