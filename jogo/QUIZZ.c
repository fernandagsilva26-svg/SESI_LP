#include <stdio.h>   
#include <stdlib.h>  
#include <ctype.h>   
#include <time.h>    

#define TOTAL_BANCO 30  
#define QTD 15          
#define ALT 4

void exibirMenu() {
  
    printf("\n==================================\n");
    printf("     MANUSABIDA & FÊCURIOSA    \n");
    printf("==================================\n");
    printf("1. Iniciar Super Desafio (15 Perguntas para cada)\n");
    printf("2. Sair\n");
    printf("Escolha uma opcao: ");
}

int validarOpcao(int min, int max) {
    int valor;
    while (scanf("%d", &valor) != 1 || valor < min || valor > max) {
        printf("Opcao invalida! Digite %d ou %d: ", min, max);
        while (getchar() != '\n'); 
    }
    return valor;
}

char pegarResposta() {
    char r;
    while (1) {
        printf("Sua resposta (A, B, C ou D): ");
        scanf(" %c", &r); 
        r = toupper(r);   
        if (r >= 'A' && r <= 'D') {
            while (getchar() != '\n'); 
            return r;
        }
        printf("Letra invalida! Use apenas A, B, C ou D.\n");
        while (getchar() != '\n');
    }
}

int realizarQuiz(char nome[], int sorteadas[]) {
    int auraTotal = 0;
    int indiceSorteado;

    char perguntas[TOTAL_BANCO][100] = {
        "Qual o maior planeta do sistema solar?", "Qual a capital da Franca?", "Quantos lados tem um hexagono?",
        "Qual o oceano que banha o Brasil?", "Quem escreveu o livro 'Dom Casmurro'?", "Qual pais inventou o videogame?",
        "Quantas cores tem o arco-iris?", "Qual o metal com simbolo quimico Au?", "Qual o pais da bossa nova?",
        "Qual personagem tem os pes virados?", "Qual o nome do satelite da Terra?", "Quem descobriu a gravidade?",
        "Qual o maior animal vivo do mundo?", "De qual banda era Freddie Mercury?", "Quantos minutos tem uma hora?",
        "Quem pintou a 'Mona Lisa'?", "Qual o maior rio do mundo em volume de agua?", "Qual o gas mais abundante na atmosfera?",
        "Em qual continente fica o Egito?", "Qual o menor pais do mundo?", "Quantos anos tem um seculo?",
        "Qual o nome do peixe-palhaco no filme Procurando Nemo?", "Qual a capital dos Estados Unidos?", "Quantos ossos tem o corpo humano adulto?",
        "Onde surgiram os Jogos Olimpicos?", "Qual inseto produz mel?", "Qual heroi e conhecido como o 'Cavaleiro das Trevas'?",
        "Quantos coracoes tem um polvo?", "Qual a formula quimica da agua?", "Como e chamado um triangulo com todos os lados iguais?"
    };

    char alternativas[TOTAL_BANCO][ALT][50] = {
        {"A) Terra", "B) Marte", "C) Jupiter", "D) Saturno"}, {"A) Londres", "B) Paris", "C) Madri", "D) Roma"},
        {"A) 5 lados", "B) 6 lados", "C) 7 lados", "D) 8 lados"}, {"A) Atlantico", "B) Pacifico", "C) Indico", "D) Artico"},
        {"A) M. Lobato", "B) M. de Assis", "C) P. Coelho", "D) J. Amado"}, {"A) Brasil", "B) EUA", "C) Japao", "D) China"},
        {"A) 5 cores", "B) 6 cores", "C) 7 cores", "D) 8 cores"}, {"A) Prata", "B) Ouro", "C) Cobre", "D) Ferro"},
        {"A) Argentina", "B) Brasil", "C) Alemanha", "D) Franca"}, {"A) Saci", "B) Curupira", "C) Iara", "D) Lobisomem"},
        {"A) Sol", "B) Lua", "C) Marte", "D) Titan"}, {"A) Newton", "B) Einstein", "C) Galileu", "D) Da Vinci"},
        {"A) Elefante", "B) Tubarao Baleia", "C) Baleia Azul", "D) Girafa"}, {"A) The Beatles", "B) Queen", "C) AC/DC", "D) Pink Floyd"},
        {"A) 50 minutos", "B) 60 minutos", "C) 100 minutos", "D) 24 minutos"}, {"A) Picasso", "B) Van Gogh", "C) Da Vinci", "D) Monet"},
        {"A) Rio Nilo", "B) Rio Amazonas", "C) Rio Mississipi", "D) Rio Congo"}, {"A) Nitrogenio", "B) Hidrogenio", "C) Oxigenio", "D) Carbono"},
        {"A) Asia", "B) Africa", "C) Europa", "D) America"}, {"A) Malta", "B) Monaco", "C) Vaticano", "D) San Marino"},
        {"A) 10 anos", "B) 50 anos", "C) 100 anos", "D) 1000 anos"}, {"A) Nemo", "B) Marlin", "C) Dory", "D) Bruce"},
        {"A) Nova York", "B) Los Angeles", "C) Washington", "D) Miami"}, {"A) 150 ossos", "B) 206 ossos", "C) 300 ossos", "D) 412 ossos"},
        {"A) Egito", "B) Grecia", "C) China", "D) Italia"}, {"A) Formiga", "B) Abelha", "C) Aranha", "D) Vespa"},
        {"A) Superman", "B) Homem Aranha", "C) Batman", "D) Thor"}, {"A) 1 coracao", "B) 2 coracoes", "C) 3 coracoes", "D) 4 coracoes"},
        {"A) CO2", "B) H2O", "C) NaCl", "D) O2"}, {"A) Escaleno", "B) Isosceles", "C) Equilatero", "D) Retangulo"}
    };

    char gabarito[TOTAL_BANCO] = {
        'C', 'B', 'B', 'A', 'B', 'B', 'C', 'B', 'B', 'B', 'B', 'A', 'C', 'B', 'B',
        'C', 'B', 'A', 'B', 'C', 'C', 'A', 'C', 'B', 'B', 'B', 'C', 'C', 'B', 'C'
    };

    for (int i = 0; i < QTD; i++) {
        do {
            indiceSorteado = rand() % TOTAL_BANCO;
        } while (sorteadas[indiceSorteado] == 1);

        sorteadas[indiceSorteado] = 1; 

        printf("\nQuestao %d de %d:\n%s\n", i + 1, QTD, perguntas[indiceSorteado]);
        for (int j = 0; j < ALT; j++) {
            printf("%s\n", alternativas[indiceSorteado][j]);
        }

        char resp = pegarResposta();

        if (resp == gabarito[indiceSorteado]) {
            printf(">> Boa, %s! Voce ACERTOU + 1000 AURA.\n", nome);
            auraTotal += 1000;
        } else {
            printf(">> BÁHHH, %s... voce ERROU - 1000 AURA! A correta era %c.\n", nome, gabarito[indiceSorteado]);
            auraTotal -= 1000;
        }
        printf("Aura atual: %d\n", auraTotal);
    }
    return auraTotal;
}

void exibirTitulo(int aura) {
    if (aura <= 200) {
        printf("Status: BETA\n");
    } else if (aura <= 2000) {
        printf("Status: OMEGA\n");
    } else {
        printf("Status: ALFA\n");
    }
}

int main() {
    srand(time(NULL));
    int opcao;
    char nome1[30], nome2[30];
    int auraJ1, auraJ2;

    do {
        exibirMenu();
        opcao = validarOpcao(1, 2);
        if (opcao == 1) {
            int historicoPerguntas[TOTAL_BANCO] = {0};

            while (getchar() != '\n');
            printf("\nDigite o nome do Jogador 1: ");
            scanf("%[^\n]", nome1);
            while (getchar() != '\n');
            printf("Digite o nome do Jogador 2: ");
            scanf("%[^\n]", nome2);
            while (getchar() != '\n');
            
            printf("\n==================================");
            printf("\n>>> VEZ DE: %s <<<", nome1);
            printf("\n==================================\n");
            auraJ1 = realizarQuiz(nome1, historicoPerguntas);
            
            printf("\nFim do turno de %s. Pressione Enter...", nome1);
            getchar();
            
            printf("\n==================================");
            printf("\n>>> VEZ DE: %s <<<", nome2);
            printf("\n==================================\n");
            auraJ2 = realizarQuiz(nome2, historicoPerguntas);
            
            printf("\nFim do turno de %s. Pressione Enter...", nome2);
            getchar();
            
            printf("\n==================================\n");
            printf("            PLACAR FINAL            \n");
            printf("==================================\n");
            
            printf("%s fez: %d de AURA | ", nome1, auraJ1);
            exibirTitulo(auraJ1);
            
            printf("%s fez: %d de AURA | ", nome2, auraJ2);
            exibirTitulo(auraJ2);
            
            printf("----------------------------------\n");
            if (auraJ1 > auraJ2) {
                printf(" VITORIA DE: %s!\n", nome1);
            } else if (auraJ2 > auraJ1) {
                printf(" VITORIA DE: %s!\n", nome2);
            } else {
                printf(" EMPATE! Ambos jogaram muito bem.\n");
            }
            printf("==================================\n");
            printf("\nPressione Enter para voltar ao menu...");
            getchar();
            system("clear");
        }
    } while (opcao != 2);
    
    printf("\nSaindo do programa... Boa sorte!\n");
    return 0;
}