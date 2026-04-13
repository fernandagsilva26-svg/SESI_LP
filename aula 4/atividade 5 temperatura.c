#include <stdio.h>

int main() {
    float temp[7], soma = 0, media;
    int i, diaQuente = 0, diaFrio = 0, acimaMedia = 0;

    // Entrada de dados
    for(i = 0; i < 7; i++) {
        printf("Digite a temperatura do dia %d: ", i + 1);
        scanf("%f", &temp[i]);
        soma += temp[i];
    }

    // Cálculo da média
    media = soma / 7;

    // Identificação dos extremos e contagem acima da média
    for(i = 0; i < 7; i++) {
        if(temp[i] > temp[diaQuente]) {
            diaQuente = i;
        }
        if(temp[i] < temp[diaFrio]) {
            diaFrio = i;
        }
        if(temp[i] > media) {
            acimaMedia++;
        }
    }

    // Exibição dos resultados
    printf("\n--- Relatório de Temperaturas ---\n");
    printf("Media semanal: %.2f graus\n", media);
    printf("Dia mais quente: Dia %d (%.1f graus)\n", diaQuente + 1, temp[diaQuente]);
    printf("Dia mais frio: Dia %d (%.1f graus)\n", diaFrio + 1, temp[diaFrio]);
    printf("Dias com temperatura acima da media: %d\n", acimaMedia);

    return 0;
}