#include <stdio.h>
int gcd(int a, int b)
{
    int tmp;
    while (b != 0)
    {
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

int main()
{
    int m, n, d;
    printf("nhap M:");
    scanf("%d", &m);
    printf("nhap N:");
    scanf("%d", &n);
    printf("nhap d:");
    scanf("%d", &d);
    printf("Voi uoc chung lon nhat la %d thi co cac cap so trong khoang [%d, %d]\n ", d, m, n);
    for (int i = m; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            if (gcd(i, j) == d)
            {
                printf("(%d,%d)\n", i, j);
            }
        }
    }
}