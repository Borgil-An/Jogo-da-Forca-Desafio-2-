#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_PALAVRAS 10
#define TAM 100

typedef struct
{
    char palavraEscolhida[TAM];
    char palavraImpressa[TAM];
    char dica[TAM];
    int letrasRestantes;
    int chancesRestantes;
} MatchData;


const char tabelaDePalavras[NUM_PALAVRAS][TAM] = {
    "BONOBO$Especie de macaco mais insana",
    "GEAR$Ferramenta em outra lingua",
    "URUBU$Raça do inimigo do pica-pau",
    "INTERNACIONAL$Maior do sul do Brasil",
    "ORVALHO$Gotas em folhas por conta da transpiração",
    "ARROZ$Grão branco presente na maioria das culinarias",
    "AMBIVALENTE$Definição de carregar dois valores",
    "CARANGUEIJO$Animal que anda de lado",
    "LEVANTAR$O que você faz após cair",
    "LAGARTO$Lacoste de elo baixo"
};

void selecionarPalavraAleatoria(const char tabelaDePalavras[][TAM], int tamanhoDaTabela, MatchData *dadosDoJogo);
void exibirPartida(const MatchData *dadosDoJogo);
void lerLetraDoUsuario(MatchData *dadosDoJogo);
void atualizarPalavra(MatchData *dadosDoJogo, char letra);
int verificarVitoria(const MatchData *dadosDoJogo);
int verificarDerrota(const MatchData *dadosDoJogo);
void limparTela(void);

int main(void) {
    MatchData dadosDoJogo;
    int escolha;

    while (1) {
        selecionarPalavraAleatoria(tabelaDePalavras, NUM_PALAVRAS, &dadosDoJogo);
        limparTela();
        printf("\nDica: %s\n", dadosDoJogo.dica);

        while (dadosDoJogo.chancesRestantes > 0 && !verificarVitoria(&dadosDoJogo) && !verificarDerrota(&dadosDoJogo)) {
            exibirPartida(&dadosDoJogo);
            lerLetraDoUsuario(&dadosDoJogo);
        }

        exibirPartida(&dadosDoJogo);

        if (verificarVitoria(&dadosDoJogo)) {
            printf("\nVocê sobreviveu!\n");
        } else {
            printf("\nVocê morreu.\n");
        }

        printf("\nQuer tentar de novo? \n1)Sim \n0)Nao:\n ");
        scanf("%d", &escolha);

        if (escolha != 1) {
            break;
        }
    }

    printf("\nObrigado por jogar\n");

    return 0;
}

void selecionarPalavraAleatoria(const char tabelaDePalavras[][TAM], int tamanhoDaTabela, MatchData *dadosDoJogo) {
    srand((unsigned int) time(NULL));
    int indice = rand() % tamanhoDaTabela;

    strcpy(dadosDoJogo->palavraEscolhida, tabelaDePalavras[indice]);

    char *palavra = strtok(dadosDoJogo->palavraEscolhida, "$");
    char *dica = strtok(NULL, "$");

    strcpy(dadosDoJogo->palavraImpressa, palavra);
    dadosDoJogo->letrasRestantes = strlen(palavra);
    dadosDoJogo->letrasRestantes = strlen(palavra);
    dadosDoJogo->chancesRestantes = 6;
    strcpy(dadosDoJogo->dica, dica);

    for (int i = 0; i < strlen(palavra); i++) {
      if (palavra[i] != ' ') {
        dadosDoJogo->palavraImpressa[i] = '-';
    } else {
        dadosDoJogo->palavraImpressa[i] = ' ';
        dadosDoJogo->letrasRestantes--;
    }
}

}

void exibirPartida(const MatchData *dadosDoJogo) {
  printf("\nPalavra: %s\n", dadosDoJogo->palavraImpressa);
  printf("Letras restantes: %d\n", dadosDoJogo->letrasRestantes);
  printf("Vidas restantes: %d\n", dadosDoJogo->chancesRestantes);
}

void lerLetraDoUsuario(MatchData *dadosDoJogo) {
    char letra;
    printf("\nDigite uma letra (ou 0 para sair): ");
    scanf(" %c", &letra);

    if (letra == '0') {
        printf("\nFujão.\n");
        exit(0);
    }

    atualizarPalavra(dadosDoJogo, letra);

    if (!strchr(dadosDoJogo->palavraEscolhida, letra)) {
        dadosDoJogo->chancesRestantes--;
    }
}

void atualizarPalavra(MatchData *dadosDoJogo, char letra) {
  for (int i = 0; i < strlen(dadosDoJogo->palavraEscolhida); i++) {
    if (dadosDoJogo->palavraEscolhida[i] == letra) {
    if (dadosDoJogo->palavraImpressa[i] == '-') {
        dadosDoJogo->letrasRestantes--;
}
    dadosDoJogo->palavraImpressa[i] = letra;
    }
}
}

int verificarVitoria(const MatchData *dadosDoJogo) {
return (dadosDoJogo->letrasRestantes == 0);
}

int verificarDerrota(const MatchData *dadosDoJogo) {
return (dadosDoJogo->chancesRestantes == 0);
}

void limparTela(void) {
system("clear||cls"); 
}

