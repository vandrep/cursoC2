#include <stdio.h>

void soma(int *num, int a, int b)
{
    *num = a + b;
}

int soma2(int nums[], int tamanho)
{
    int soma = 0;
    
    for (int i = 0; i < tamanho; i++)
    {
        soma += nums[i];
    }
    return soma;
}

int main()
{
    int somaV;

    soma(&somaV, 1, 2);


    int nums[3];
    nums[0] = 10;
    nums[1] = 20;
    nums[2] = 30;

    printf("%d\n", somaV);
    printf("%d\n", soma2(nums, 3));
}