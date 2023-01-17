#include <stdio.h>
#include <math.h>
int mod(int a, int b, int n)
{
    return ((a % n) * (b % n)) % n;
}

int kiemtratinhgnuyento(int m)
{
    if (m == 0 || m == 1)
        return 0;
    for (int k = 2; k <= sqrt(m); k++)
    {
        if (m % k == 0)
            return 0;
    }
    return 1;
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

int main()
{
    int a, k, n, b, K[100], j = 0;
    printf("nhap a:");
    scanf("%d", &a);
    printf("nhap b:");
    scanf("%d", &b);
    printf("nhap k:");
    scanf("%d", &k);
    printf("%d\n", nhanBinhPhuongCoLap(a, b, k));
    if (kiemtratinhgnuyento(nhanBinhPhuongCoLap(a, b, k)))
    {
        printf("Yes!\n");
    }
    else
    {
        printf("No!\n");
    }
}