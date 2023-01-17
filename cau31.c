#include <stdio.h>
#include <math.h>

long long int kiemtratinhgnuyento(long long int m)
{
    if (m == 0 || m == 1)
        return 0;
    for (long long int k = 2; k <= sqrt(m); k++)
    {
        if (m % k == 0)
            return 0;
    }
    return 1;
}

long long int mod(long long int a, long long int b, long long int n)
{
    return ((a % n) * (b % n)) % n;
}

long long int nhanBinhPhuongCoLap(long long int a, long long int k, long long int n)
{
    long long int A = a, b = 1;
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
    long long int MSV, SBD, MSVs, MSVt, n;
    n = 123456;
    printf("Nhap MSV:");
    scanf("%lld", &MSV);
    printf("Nhap SBD: ");
    scanf("%lld", &SBD);
    MSVs = MSV + 1;
    MSVt = MSV - 1;
    while (MSVt >= 0 && kiemtratinhgnuyento(MSVt) == 0)
        MSVt--;
    while (kiemtratinhgnuyento(MSVs) == 0)
        MSVs++;
    if ((MSVs - MSV) >= (MSV - MSVt))
    {
        MSV = MSVt;
    }
    else
    {
        MSV = MSVs;
    }

    printf("%lld\n", MSV);
    printf("%lld ^ %lld mod %lld = %lld", SBD, MSV, n, nhanBinhPhuongCoLap(SBD, MSV, n));
}