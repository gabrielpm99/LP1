#include <stdio.h>

float converterFahrenheit(float celsius) {
    // Calcula a partir da fórmula de conversão
    return ((celsius * (9.0/5.0)) + 32);
}

int main() {
    float celsius;
    
    printf("Digite uma temperatura em Celsius: ");
    scanf("%f", &celsius);

    float fahrenheit = converterFahrenheit(celsius);

    printf("A temperatura %.1f em Celsius equivale a %.1f em Fahrenheit", celsius, fahrenheit);

    return 0;
}
