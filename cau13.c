#include <stdio.h>
#include <math.h>
#include <stdbool.h>
bool check(long long int n)
{
    int d = 2;
    if (n == 0 || n == 1)
    {
        return false;
    }
    else
    {
        for (long long int i = 2; i <= sqrt(n); i++)
        {
            if (n % i == 0)
                d++;
        }
        return d == 2;
    }
}
int main()
{
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);

    int i, j;
    for (i = 2; i <= n; i++)
    {
        if (check(i) == 1)
        {
            for (j = i; j <= n; j++)
            {
                if (check(j) == 1)
                {
                    int tong = i + j;
                    int hieu = abs(i - j);
                    if (check(tong) == 1 && check(hieu) == 1)
                    {
                        printf("\nHai so nguyen to can tim la: %d va %d", i, j);
                    }
                }
            }
        }
    }
    return 0;
}