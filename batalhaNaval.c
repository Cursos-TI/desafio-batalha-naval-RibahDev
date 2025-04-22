#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO])
{
    printf("Tabuleiro:\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++)
    {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++)
        {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Validação e posicionamento horizontal
int podePosicionarHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna)
{
    if (coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO)
        return 0;
    for (int i = 0; i < TAMANHO_NAVIO; i++)
    {
        if (tabuleiro[linha][coluna + i] != 0)
            return 0;
    }
    return 1;
}
void posicionarHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna)
{
    for (int i = 0; i < TAMANHO_NAVIO; i++)
    {
        tabuleiro[linha][coluna + i] = 3;
    }
}

// Validação e posicionamento vertical
int podePosicionarVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna)
{
    if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO)
        return 0;
    for (int i = 0; i < TAMANHO_NAVIO; i++)
    {
        if (tabuleiro[linha + i][coluna] != 0)
            return 0;
    }
    return 1;
}
void posicionarVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna)
{
    for (int i = 0; i < TAMANHO_NAVIO; i++)
    {
        tabuleiro[linha + i][coluna] = 3;
    }
}

// Validação e posicionamento diagonal principal 
int podePosicionarDiagonalPrincipal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna)
{
    if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO || coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO)
        return 0;
    for (int i = 0; i < TAMANHO_NAVIO; i++)
    {
        if (tabuleiro[linha + i][coluna + i] != 0)
            return 0;
    }
    return 1;
}
void posicionarDiagonalPrincipal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna)
{
    for (int i = 0; i < TAMANHO_NAVIO; i++)
    {
        tabuleiro[linha + i][coluna + i] = 3;
    }
}

// Validação e posicionamento diagonal secundária 
int podePosicionarDiagonalSecundaria(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna)
{
    if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO || coluna - TAMANHO_NAVIO + 1 < 0)
        return 0;
    for (int i = 0; i < TAMANHO_NAVIO; i++)
    {
        if (tabuleiro[linha + i][coluna - i] != 0)
            return 0;
    }
    return 1;
}
void posicionarDiagonalSecundaria(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna)
{
    for (int i = 0; i < TAMANHO_NAVIO; i++)
    {
        tabuleiro[linha + i][coluna - i] = 3;
    }
}

int main()
{
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Coordenadas dos navios (você pode mudar conforme desejar)
    int linhaH = 0, colunaH = 1;   // Horizontal
    int linhaV = 4, colunaV = 6;   // Vertical
    int linhaD1 = 2, colunaD1 = 2; // Diagonal principal
    int linhaD2 = 6, colunaD2 = 8; // Diagonal secundária

    // Posiciona navio horizontal
    if (podePosicionarHorizontal(tabuleiro, linhaH, colunaH))
    {
        posicionarHorizontal(tabuleiro, linhaH, colunaH);
    }
    else
    {
        printf("Erro ao posicionar navio horizontal.\n");
    }

    // Posiciona navio vertical
    if (podePosicionarVertical(tabuleiro, linhaV, colunaV))
    {
        posicionarVertical(tabuleiro, linhaV, colunaV);
    }
    else
    {
        printf("Erro ao posicionar navio vertical.\n");
    }

    // Posiciona navio diagonal principal
    if (podePosicionarDiagonalPrincipal(tabuleiro, linhaD1, colunaD1))
    {
        posicionarDiagonalPrincipal(tabuleiro, linhaD1, colunaD1);
    }
    else
    {
        printf("Erro ao posicionar navio diagonal ↘.\n");
    }

    // Posiciona navio diagonal secundária
    if (podePosicionarDiagonalSecundaria(tabuleiro, linhaD2, colunaD2))
    {
        posicionarDiagonalSecundaria(tabuleiro, linhaD2, colunaD2);
    }
    else
    {
        printf("Erro ao posicionar navio diagonal ↙.\n");
    }

    // Exibir tabuleiro final
    exibirTabuleiro(tabuleiro);

    return 0;
}
