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
    long long int N, k = 0, q = 0, p = 0, s = 0, Tong = 0;

    printf("nhap N: ");
    scanf("%lld", &N);
    for (long long int i = 1; i <= N; i++)
    {
        if (N % i == 0)
        {
            s++;
            p += i;
            if (check(i) == true)
            {
                q += i;
                k++;
            }
        }
    }
    Tong = N + p + s - q - k;
    printf("Vay ket qua la %lld+%lld+%lld-%lld-%lld=%lld", N, p, s, q, k, Tong);
}