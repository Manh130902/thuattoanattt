#include <stdio.h>
#include <math.h>
#include <stdbool.h>
bool checksnt(int n)
{
    if (n < 2)
        return false;
    else
    {
        for (int i = 2; i <= sqrt(n); i++)
        {
            if (n % i == 0)
                return false;
        }
        return true;
        ;
    }
}
int sodaonguoc(long long int n)
{
    long long int res = 0;
    while (n > 0)
    {
        long long int tmp = n % 10;
        res = res * 10 + tmp;
        n = n / 10;
    }
    return res;
}
int main()
{
    long long int n;
    printf("nhap so N : ");
    scanf("%lld", &n);
    while (n <= 0)
    {
        printf("nhap lai so N : ");
        scanf("%lld", &n);
    }

    for (long long int i = 0; i < n; i++)
    {
        long long int res = sodaonguoc(i);
        if (checksnt(i) == true && checksnt(res) == true)
        {
            printf("%lld    ", i);
        }
    }
    return 0;
}
