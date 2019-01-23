#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

#define TAMANHO_PALAVRA 20

//Variáveis Globais
char palavraSecreta[TAMANHO_PALAVRA];
char chutes[26];
int chutesDados = 0;

void abertura()
{
    printf("/*****************/\n");
    printf("/* Jogo de Forca */\n");
    printf("/*****************/\n\n");
}

void chuta()
{
    char chute;
    scanf(" %c", &chute);

    chutes[chutesDados] = chute;
    chutesDados++;
}

int jaChutou(char letra)
{
    for (int j = 0; j < chutesDados; j++)
    {
        if (letra == chutes[j])
        {
            return 1;
            break;
        }
    }
    return 0;
}

void desenhaForca()
{
    for (int i = 0; i < strlen(palavraSecreta); i++)
    {
        if (jaChutou(palavraSecreta[i]))
        {
            printf("%c ", palavraSecreta[i]);
        }
        else
        {
            printf("_ ");
        }
    }
    printf("\n");
}

void adicionaPalavra()
{
    char quer;

    printf("Você deseja adicionar uma nova palavra no jogo? (S/N)");
    scanf(" %c", &quer);

    if (quer == 'S')
    {
        char novaPalavra[TAMANHO_PALAVRA];
        printf("Qual a nova palavra?");
        scanf("%s", novaPalavra);

        FILE *f = fopen("palavras.txt", "r+");

        if (f == 0)
        {
            printf("Desculpe, banco de dados não disponível\n\n");
            exit(1);
        }

        int qtd;
        fscanf(f, "%d", &qtd);
        qtd++;

        fseek(f, 0, SEEK_SET);
        fprintf(f, "%d", qtd);

        fseek(f, 0, SEEK_END);
        fprintf(f, "\n%s", novaPalavra);

        fclose(f);
    }
}

void escolhePalavra()
{
    FILE *f = fopen("palavras.txt", "r");

    if (f == 0)
    {
        printf("Desculpe, banco de dados não disponível\n\n");
        exit(1);
    }

    int qtdDePalavras;
    fscanf(f, "%d", &qtdDePalavras);

    srand(time(0));
    int randomico = rand() % qtdDePalavras;

    for (int i = 0; i <= randomico; i++)
    {
        fscanf(f, "%s", palavraSecreta);
    }

    fclose(f);
}

int acertou()
{
    for (int i = 0; i < strlen(palavraSecreta); i++)
    {
        if (!jaChutou(palavraSecreta[i]))
            return 0;
    }
    printf("Parabéns!!! Você Ganhou!!!\n");
    printf("             ___________   \n");
    printf("            '._==_==_=_.'  \n");
    printf("            .-\\:      /-.  \n");
    printf("           | (|:.     |) | \n");
    printf("            '-|:.     |-'  \n");
    printf("              \\::.    /    \n");
    printf("               '::. .'     \n");
    printf("                 ) (       \n");
    printf("               _.' '._     \n");
    printf("          jgs `\"\"\"\"\"\"\"`    \n");
    return 1;
}

int enforcou()
{
    int erros = 0;
    for (int i = 0; i < chutesDados; i++)
    {
        int existe = 0;

        for (int j = 0; j < strlen(palavraSecreta); j++)
        {
            if (chutes[i] == palavraSecreta[j])
            {
                existe = 1;
                break;
            }
        }

        if (!existe)
            erros++;
    }

    if (erros >= 5)
    {
        printf("Você Perdeu!!!\n");
        printf("            _,.-------.,_                        \n");
        printf("        ,;~'             '~;,                    \n");
        printf("      ,;                     ;,                  \n");
        printf("     ;                         ;                 \n");
        printf("    ,'                         ',                \n");
        printf("   ,;                           ;,               \n");
        printf("   ; ;      .           .      ; ;               \n");
        printf("   | ;   ______       ______   ; |               \n");
        printf("   |  `/~\"     ~\" . \"     ~\"~\'  |               \n");
        printf("   |  ~  ,-~~~^~, | ,~^~~~-,  ~  |               \n");
        printf("    |   |        }:{        |   |                \n");
        printf("    |   l       / | \\       !   |                \n");
        printf("    .~  (__,.--\".^.\"--.,__)  ~.                \n");
        printf("    |     ---;' / | \\ `;---     |                \n");
        printf("     \\__.       \\/^\\/       .__/                 \n");
        printf("      V| \\                 / |V                  \n");
        printf("       | |T~\\___!___!___/~T| |                   \n");
        printf("       | |`IIII_I_I_I_IIII'| |                   \n");
        printf("       |  \\,III I I I III,/  |                   \n");
        printf("        \\   `~~~~~~~~~~'    /                    \n");
        printf("          \\   .       .   /     -dcau (4/15/95)  \n");
        printf("            \\.    ^    ./                        \n");
        printf("              ^~~~^~~~^                          \n");
    }
    return erros >= 5;
}

int main()
{
    SetConsoleOutputCP(65001);

    escolhePalavra();
    abertura();

    while (!acertou() && !enforcou())
    {
        desenhaForca();
        chuta();
    }
    desenhaForca();

    adicionaPalavra();
}