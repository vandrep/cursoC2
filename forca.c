#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <locale.h>

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    char palavraSecreta[20];

    sprintf(palavraSecreta, "MELANCIA");

    int acertou = 0;
    int enforcou = 0;

    char chutes[26];
    int tentativas = 0;

    do
    {
        for (int i = 0; i < strlen(palavraSecreta); i++)
        {
            int achou = 0;

            for (int j = 0; j < tentativas; j++)
            {
                if (palavraSecreta[i] == chutes[j])
                {
                    achou = 1;
                    break;
                }
            }
            if (achou)
            {
                printf("%c ", palavraSecreta[i]);
            }
            else
            {
                printf("_ ");
            }
        }
        printf("\n");
        char chute;
        scanf(" %c", &chute);

        chutes[tentativas] = chute;
        tentativas++;
        // for (int i = 0; i < strlen(palavraSecreta); i++)
        // {
        //     if (palavraSecreta[i] == chute)
        //     {
        //         printf("A posição %d tem essa letra!\n", i);
        //     }
        // }
    } while (!acertou && !enforcou);
}