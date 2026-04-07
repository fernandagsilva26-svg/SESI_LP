#include <stdio.h>

int main() {
    int n, soma = 0;
    do {
        printf("Digite um numero (0 para parar): ");
        scanf("%d", &n);
        soma += n;
    } while (n != 0);
    printf("Soma total: %d\n", soma);
    return 0;
}