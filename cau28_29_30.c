#include <stdio.h>
#include <math.h>
int laSNT(int n)
{
    if (n < 2)
        return 0;
    if (n == 2)
        return 1;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int mod(int a, int b, int n)
{
    return ((a % n) * (b % n)) % n;
}

int nhanBinhPhuongCoLap(int a, int k, int n)
{
    int A = a, b = 1;
    if (k % 2 == 1)
        b = a;
    k /= 2;
    while (k > 0)
    {
        A = mod(A, A, n);
        if (k % 2 == 1)
            b = mod(b, A, n);
        k /= 2;
    }
    return b;
}

int check(int n)
{
    for (int i = 1; i < n; i++)
    {
        if (ucln(n, i) == 1)
        {
            if (nhanBinhPhuongCoLap(i, n - 1, n) != 1)
                return 0;
        }
    }
    return 1;
}

int ucln(int a, int b)
{
    int tmp;
    while (b > 0)
    {
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

int main()
{
    int n;
    printf("nhap n ");
    scanf("%d", &n);
    for (int i = 2; i <= n; i++)
    {
        if (laSNT(i) == 0 && check(i) == 1)
        {
            printf("%d ", i);
        }
    }
}