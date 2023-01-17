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
    int n, i, j, k, flag;
    printf("\nNhap n: ");
    scanf("%d", &n);
    int A[n];
    for (i = 2; i < n; i++)
    {
        A[i] = 0;
        A[1]=1;
        for (j = 2; j < n; j++)
        {
            if (check(j))
            {
                if (i % (j * j) == 0)
                {
                    A[i] = 1;
                }
            }
        }
    }
    for (i = 2; i < n; i++)
    {
        if (A[i] == 1)
            printf(" %d ", i);
    }
}