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
    int p, q, a;
    while (!kiemtratinhgnuyento(q))
    {
        q = rand() % 100;
    }
    while (!kiemtratinhgnuyento(p))
    {

        p = rand() % 100;
    }
    printf("%d\n", p);
    printf("%d\n", q);
    for (int i = 0; i < 100; i++)
    {
        if (kiemtratinhgnuyento(nhanBinhPhuongCoLap(i, p, q)))
        {
            printf("%d ", i);
        }
    }
}