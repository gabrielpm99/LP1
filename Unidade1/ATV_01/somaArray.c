#include <stdio.h>

int lerNumeros(int N, int* numeros) {
    // Lê N números e armazena no array numeros
    for(int i = 0; i < N; i++) {
        int num;
        printf("Digite um numero inteiro: ");
        scanf("%i", &num);

        numeros[i] = num;
    }
}

int imprimirArray(int N, int* numeros) {
    // Inicia a impressão do array
    printf("O array eh: [");

    // Imprime cada número do array seguido de vírgula.
    for(int i = 0; i < N - 1; i++) {
        printf("%i, ", numeros[i]);
    }

    // Finaliza a impressão do array
    printf("%i] \n", numeros[N - 1]);
}

int calcularSoma(int N, int* numeros) {
    int total = 0;

    // Soma todos os números e armazena na variável total
    for(int i = 0; i < N; i++) {
        total += numeros[i];
    }

    return total;
}

int main() {
    int N = 5;
    int numeros[N];

    lerNumeros(N, numeros);
    imprimirArray(N, numeros);
    int total = calcularSoma(N, numeros);

    printf("A soma dos numeros do array eh: %i", total);

    return 0;
}
