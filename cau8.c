#include <stdio.h>
#include <stdbool.h>
#include <math.h>
bool isPrime(long long int n)
{
    int dem = 0;
    if (n <= 2)
        return false;
    for (long long int i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
            dem++;
    }
    return dem == 1;
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
        if (isPrime(i))
            printf("%lld  ", i);
    }
    return 0;
}