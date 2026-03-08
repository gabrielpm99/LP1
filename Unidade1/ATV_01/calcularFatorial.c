#include <stdio.h>

int calcularFatorial(int N) {
    int total = 1;

    // Calcula o fatorial do número
    for(int i = 1; i <= N; i++) {
        total *= i;
    }

    return total;
}

int main() {
    int N;
    printf("Digite um numero inteiro positivo para calcular o fatorial: ");
    scanf("%i", &N);

    int fatorial = calcularFatorial(N);

    printf("O fatorial do numero %i eh %i", N, fatorial);

    return 0;
}
