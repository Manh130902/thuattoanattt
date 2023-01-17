#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool check(int n)
{
    if(n<2) return false;
    else
    {
        for (int i = 2; i <= sqrt(n); i++)
        {
            if (n % i == 0)
                return false;
        }
        return true;;
    }
}

int main()
{
    long long int n, d, i;
    printf("\nNhap n: ");
    scanf("%lld", &n);
    while(n<2 || n>10){
        printf("\nnhap lai n: ");
        scanf("%lld", &n);
    }
    d = pow(10, n - 1);
    n = pow(10, n) - 1;
    printf("(");
    for (i = d; i <= n; i++)
    {
        if (check(i) == true)
            printf("%lld ", i);
    }
    printf(")");
}