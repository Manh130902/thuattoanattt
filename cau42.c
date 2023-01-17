#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
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
    srand(time(NULL));
    int p, N, a;
    printf("nhap N: ");
    scanf("%d", &N);

    while (!kiemtratinhgnuyento(p))
    {
        p = rand() % 100;
    }
    printf("%d\n", p);
    for (int i = 0; i < N; i++)
    {
        if (kiemtratinhgnuyento(nhanBinhPhuongCoLap(i, p, N)))
        {
            printf("%d ^ %d mod %d = %d\n", i, p, N, nhanBinhPhuongCoLap(i, p, N));
        }
    }
}