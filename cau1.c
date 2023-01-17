#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool check(int n)
{
    int d = 2;
    for (int i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
            d++;
    }
    return d == 4;
}

int main()
{
    int n, d, i;
    printf("\nNhap n: ");
    scanf("%d", &n);
    while (n <= 0)
    {
        printf("\nnhap lai n: ");
        scanf("%d", &n);
    }
    printf("(");
    for (i = 0; i <= n; i++)
    {
        if (check(i) == true)
            printf("%d ", i);
    }
    printf(")");
}