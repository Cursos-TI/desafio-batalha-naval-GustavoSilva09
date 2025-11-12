#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.
    int i, j;

    int const tamanhoNavios = 3;
    int const tamanhoMatriz = 10;
    int const agua = 0;
    // Inicializa toda a matriz com 0 (água)
    int tabuleiro[10][10] = {0};

    // Vetores representando os navios (3 = parte do navio)
    int navioH[3] = {3, 3, 3}; // Navio horizontal
    int navioV[3] = {3, 3, 3}; // Navio vertical
    int navioDiagonal1[3] = {3, 3, 3}; // Navio diagonal 1
    int navioDiagonal2[3] = {3, 3, 3}; // Navio diagonal 2

    // Posição inicial para o navio horizontal
    int linhaInicioH = 2; // 3ª linha (índice 2)
    int colunaInicioH = 4; // 5ª coluna (índice 4)

    // Posição inicial para o navio vertical
    int linhaInicioV = 5; // 6ª linha (índice 5)
    int colunaInicioV = 7; // 8ª coluna (índice 7)

    // Posição inicial para o navio diagonal 1
    int linhaInicioD1 = 2; // 3ª linha (índice 2)
    int colunaInicioD1 = 1; // 2ª coluna (índice 1)
    
    // Posição inicial para o navio diagonal 2
    int linhaInicioD2 = 6; // 7ª linha (índice 6)
    int colunaInicioD2 = 5; // 6ª coluna (índice 5) 

    // Verificação se navio horizontal cabe na matriz 
    if (colunaInicioH + tamanhoNavios > tamanhoMatriz) {
        printf("Erro: Navio horizontal não cabe na matriz!\n");
        return 1;
    }

     // Verificação de sobreposição navio horizontal (simples)
    for (j = 0; j < tamanhoNavios; j++) {
        if (tabuleiro[linhaInicioH][colunaInicioH + j] != agua) {
            printf("Erro: Sobreposição de navios na posição horizontal!\n");
            return 1;
        }
    }

     // Coloca o navio horizontal na matriz
    for (j = 0; j < 3; j++) {
        tabuleiro[linhaInicioH][colunaInicioH + j] = navioH[j];
    }

    // Verificação se navio vertical cabe na matriz
    if (linhaInicioV + tamanhoNavios > tamanhoMatriz) {
        printf("Erro: Navio vertical não cabe na matriz!\n");
        return 1;
    }

    // Verificação de sobreposição navio vertical (simples)
    for (i = 0; i < tamanhoNavios; i++) {
        if (tabuleiro[linhaInicioV + i][colunaInicioV] != agua) {
            printf("Erro: Sobreposição de navios na posição vertical!\n");
            return 1;
        }
    }

    // Coloca o navio vertical na matriz
    for (i = 0; i < 3; i++) {
        tabuleiro[linhaInicioV + i][colunaInicioV] = navioV[i];
    }

    // Verificação se navio diagonal 1 cabe na matriz 
    if (linhaInicioD1 + tamanhoNavios > tamanhoMatriz || colunaInicioD1 + tamanhoNavios > tamanhoMatriz) {
        printf("Erro: Navio diagonal não cabe na matriz!\n");
        return 1;
    }

    // Verificação de sobreposição navio diagonal 1 (simples) 
    for (i = 0; i < tamanhoNavios; i++) {
        if (tabuleiro[linhaInicioD1 + i][colunaInicioD1 + i] != agua) {
            printf("Erro: Sobreposição de navios na posição diagonal!\n");
            return 1;
        }
    }

    // Coloca o navio diagonal 1 na matriz 
    for (i = 0; i < 3; i++) {
        tabuleiro[linhaInicioD1 + i][colunaInicioD1 + i] = navioDiagonal1[i];
    }

    // Verificação se navio diagonal 2 cabe na matriz
    if (linhaInicioD2 + tamanhoNavios > tamanhoMatriz || colunaInicioD2 - tamanhoNavios < 0) {
    printf("Erro: Navio diagonal 2 não cabe na matriz!\n");
    return 1;
    }

    // Verificação de sobreposição navio diagonal 2 
    for (i = 0; i < tamanhoNavios; i++) {
        if (tabuleiro[linhaInicioD2 + i][colunaInicioD2 - i] != agua) {
            printf("Erro: Sobreposição de navios na posição diagonal 2!\n");
            return 1;
    }
    }

    // Coloca o navio diagonal 2 na matriz 
    for (i = 0; i < tamanhoNavios; i++) {
        tabuleiro[linhaInicioD2 + i][colunaInicioD2 - i] = navioDiagonal2[i];
    }


    // Vetores para rótulos de coordenadas
    char letras[10] = {'A','B','C','D','E','F','G','H','I','J'};
    int numeros[10] = {1,2,3,4,5,6,7,8,9,10};


    printf("      TABULEIRO BATALHA NAVAL\n");
    // Cabeçalho de letras (colunas)
    printf("    ");
    for (i = 0; i < 10; i++) {
        printf(" %c ", letras[i]);
    }
    printf("\n");

    // Linhas com números + conteúdo da matriz
    for (i = 0; i < 10; i++) {
        printf("%2d  ", numeros[i]);  // número da linha
        for (j = 0; j < 10; j++) {
            printf(" %d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
