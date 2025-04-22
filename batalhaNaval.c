#include <stdio.h>

// Tamanho fixo do tabuleiro e navios
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

// Função para imprimir o tabuleiro
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

// Função para verificar se é possível posicionar um navio horizontal
int podePosicionarHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna)
{
    if (coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO)
        return 0; // Ultrapassa o limite do tabuleiro

    for (int i = 0; i < TAMANHO_NAVIO; i++)
    {
        if (tabuleiro[linha][coluna + i] != 0)
            return 0; // Sobreposição
    }

    return 1;
}

// Função para posicionar navio horizontal
void posicionarNavioHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna)
{
    for (int i = 0; i < TAMANHO_NAVIO; i++)
    {
        tabuleiro[linha][coluna + i] = 3;
    }
}

// Função para verificar se é possível posicionar um navio vertical
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

// Função para posicionar navio vertical
void posicionarNavioVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna)
{
    for (int i = 0; i < TAMANHO_NAVIO; i++)
    {
        tabuleiro[linha + i][coluna] = 3;
    }
}

int main()
{
    // Inicializa o tabuleiro com água (0)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Coordenadas iniciais dos navios (podem ser alteradas conforme o teste)
    int linhaHorizontal = 2, colunaHorizontal = 4;
    int linhaVertical = 5, colunaVertical = 1;

    // Verifica e posiciona navio horizontal
    if (podePosicionarHorizontal(tabuleiro, linhaHorizontal, colunaHorizontal))
    {
        posicionarNavioHorizontal(tabuleiro, linhaHorizontal, colunaHorizontal);
    }
    else
    {
        printf("Erro: Não foi possível posicionar o navio horizontal.\n");
    }

    // Verifica e posiciona navio vertical
    if (podePosicionarVertical(tabuleiro, linhaVertical, colunaVertical))
    {
        posicionarNavioVertical(tabuleiro, linhaVertical, colunaVertical);
    }
    else
    {
        printf("Erro: Não foi possível posicionar o navio vertical.\n");
    }

    // Exibe o tabuleiro com os navios posicionados
    exibirTabuleiro(tabuleiro);

    return 0;
}
