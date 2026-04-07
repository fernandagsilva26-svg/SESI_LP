
#include <stdio.h>

int main() {
    int n;
    printf("Digite onde comeca a contagem: ");
    scanf("%d", &n);
    while (n >= 0) {
        printf("%d ", n);
        n--;
    }
    return 0;
}