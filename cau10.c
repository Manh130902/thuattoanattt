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
    long long int uoc = 0, uocnt = 0, N;

    printf("nhap N: ");
    scanf("%lld", &N);
    for (long long int i = 1; i <= N; i++)
    {
        if (N % i == 0)
        {
            uoc++;
            if (check(i) == true)
            {
                uocnt++;
            }
        }
    }
    printf("so uoc cua %lld la %lld\n", N, uoc);
    printf("so uoc cua %lld la %lld\n", N, uocnt);
}