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
    int N;
    printf("nhap N: ");
    scanf("%lld", &N);
    for (int i = 0; i < N; i++)
    {
        if (check(i) && check(i + 2))
        {
            printf("cac cap so la: %d va %d\n", i, i + 2);
        }
    }
    return 0;
}