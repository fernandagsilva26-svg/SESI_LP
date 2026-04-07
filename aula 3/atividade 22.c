#include <stdio.h>

int main() {
    int n;
    do {
        printf("Digite um numero positivo: ");
        scanf("%d", &n);
        if (n <= 0) printf("Invalido! ");
    } while (n <= 0);
    printf("Voce digitou: %d\n", n);
    return 0;
}