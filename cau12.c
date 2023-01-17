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
    long long int n, j = 0, Tong = 0, flag = 1;
    printf("nhap so N : ");
    scanf("%lld", &n);
    long long int a[n];
    for (long long int i = 0; i < n; i++)
    {
        if (check(i))
        {
            a[j] = i;
            ++j;
        }
    }
    if (n < 17)
    {
        printf("NO");
    }
    else
    {
        for (long long int i = 0; i < j - 4; i++)
        {
            Tong = a[i] + a[i + 1] + a[i + 2] + a[i + 3];
            for (long long int k = 2; k <= sqrt(Tong); k++)
            {
                if (Tong % k == 0)
                    flag = 0;
            }
            if (flag == 1)
                printf("\n%lld %lld %lld %lld", a[i], a[i + 1], a[i + 2], a[i + 3]);
        }
    }
    return 0;
}