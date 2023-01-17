#include <stdio.h>
#include <math.h>
int gcd(int a, int b)
{
    int tmp;
    if (a == 0 || b == 0)
        return 0;
    while (b != 0)
    {
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

int kiemtratinhgnuyento(int m)
{
    if (m == 0 || m == 1)
        return 0;
    for (int k = 2; k <= sqrt(m); k++)
    {
        if (m % k == 0)
            return 0;
    }
    return 1;
}

int main()
{
    int a, b;
    do
    {
        printf("nhap vao so a : ");
        scanf("%d", &a);
        printf("nhap vao so b :");
        scanf("%d", &b);
    } while (a < 0 || b > 1000);
    for (int i = a; i <= b; i++)
    {
        for (int j = i+1; j <= b; j++)
        {
            int d = gcd(i, j);
            if (kiemtratinhgnuyento(d) == 1)
            {
                printf("[%d %d] gcd: %d \n", i, j, d);
            }
        }
    }
}
