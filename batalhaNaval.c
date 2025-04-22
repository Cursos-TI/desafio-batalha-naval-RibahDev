#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 10
#define TAM_HAB 5
#define NAVIO 3
#define AGUA 0
#define HABILIDADE 5

// Exibe o tabuleiro com símbolos visuais
void exibirTabuleiro(int tabuleiro[TAM][TAM])
{
    printf("\nTabuleiro:\n");
    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            if (tabuleiro[i][j] == AGUA)
                printf("~ ");
            else if (tabuleiro[i][j] == NAVIO)
                printf("■ ");
            else if (tabuleiro[i][j] == HABILIDADE)
                printf("* ");
        }
        printf("\n");
    }
}

// Aplica uma matriz de habilidade no tabuleiro
void aplicarHabilidade(int tabuleiro[TAM][TAM], int habilidade[TAM_HAB][TAM_HAB], int origemLinha, int origemColuna)
{
    int offset = TAM_HAB / 2;
    for (int i = 0; i < TAM_HAB; i++)
    {
        for (int j = 0; j < TAM_HAB; j++)
        {
            int linha = origemLinha - offset + i;
            int coluna = origemColuna - offset + j;

            // Verifica se a posição está dentro dos limites do tabuleiro
            if (linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM)
            {
                if (habilidade[i][j] == 1 && tabuleiro[linha][coluna] != NAVIO)
                {
                    tabuleiro[linha][coluna] = HABILIDADE;
                }
            }
        }
    }
}

// Gera habilidade em formato de cone (apontando para baixo)
void gerarCone(int habilidade[TAM_HAB][TAM_HAB])
{
    memset(habilidade, 0, sizeof(int) * TAM_HAB * TAM_HAB);
    for (int i = 0; i < TAM_HAB; i++)
    {
        for (int j = 0; j < TAM_HAB; j++)
        {
            if (j >= (TAM_HAB / 2 - i) && j <= (TAM_HAB / 2 + i) && i <= TAM_HAB / 2)
            {
                habilidade[i][j] = 1;
            }
        }
    }
}

// Gera habilidade em formato de cruz
void gerarCruz(int habilidade[TAM_HAB][TAM_HAB])
{
    memset(habilidade, 0, sizeof(int) * TAM_HAB * TAM_HAB);
    for (int i = 0; i < TAM_HAB; i++)
    {
        for (int j = 0; j < TAM_HAB; j++)
        {
            if (i == TAM_HAB / 2 || j == TAM_HAB / 2)
            {
                habilidade[i][j] = 1;
            }
        }
    }
}

// Gera habilidade em formato de losango
void gerarOctaedro(int habilidade[TAM_HAB][TAM_HAB])
{
    memset(habilidade, 0, sizeof(int) * TAM_HAB * TAM_HAB);
    for (int i = 0; i < TAM_HAB; i++)
    {
        for (int j = 0; j < TAM_HAB; j++)
        {
            if (abs(i - TAM_HAB / 2) + abs(j - TAM_HAB / 2) <= TAM_HAB / 2)
            {
                habilidade[i][j] = 1;
            }
        }
    }
}

// Posiciona um navio horizontal de tamanho 3
void posicionarHorizontal(int tabuleiro[TAM][TAM], int linha, int coluna)
{
    for (int i = 0; i < 3 && coluna + i < TAM; i++)
    {
        tabuleiro[linha][coluna + i] = NAVIO;
    }
}

// Posiciona um navio vertical de tamanho 3
void posicionarVertical(int tabuleiro[TAM][TAM], int linha, int coluna)
{
    for (int i = 0; i < 3 && linha + i < TAM; i++)
    {
        tabuleiro[linha + i][coluna] = NAVIO;
    }
}

// Posiciona um navio diagonal
void posicionarDiagonalPrincipal(int tabuleiro[TAM][TAM], int linha, int coluna)
{
    for (int i = 0; i < 3 && linha + i < TAM && coluna + i < TAM; i++)
    {
        tabuleiro[linha + i][coluna + i] = NAVIO;
    }
}

// Posiciona um navio diagonal
void posicionarDiagonalSecundaria(int tabuleiro[TAM][TAM], int linha, int coluna)
{
    for (int i = 0; i < 3 && linha + i < TAM && coluna - i >= 0; i++)
    {
        tabuleiro[linha + i][coluna - i] = NAVIO;
    }
}

int main()
{
    int tabuleiro[TAM][TAM] = {0};
    int cone[TAM_HAB][TAM_HAB], cruz[TAM_HAB][TAM_HAB], octaedro[TAM_HAB][TAM_HAB];

    // Posiciona navios
    posicionarHorizontal(tabuleiro, 0, 1);
    posicionarVertical(tabuleiro, 4, 6);
    posicionarDiagonalPrincipal(tabuleiro, 2, 2);
    posicionarDiagonalSecundaria(tabuleiro, 6, 8);

    // Gera habilidades
    gerarCone(cone);
    gerarCruz(cruz);
    gerarOctaedro(octaedro);

    // Aplica habilidades no tabuleiro
    aplicarHabilidade(tabuleiro, cone, 3, 5);
    aplicarHabilidade(tabuleiro, cruz, 7, 3);
    aplicarHabilidade(tabuleiro, octaedro, 5, 5);

    // Exibe resultado
    exibirTabuleiro(tabuleiro);

    return 0;
}
