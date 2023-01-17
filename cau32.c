#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
int ckeckSNT(long long int n)
{
    if (n < 2)
        return 0;
    if (n == 2 || n == 3)
        return 1;
    if (n % 2 == 0 || n % 3 == 0)
        return 0;
    for (long long int i = 5; i <= sqrt(n); i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return 0;
    return 1;
}

long long int GCD(long long int a, long long int b)
{
    if (a < b)
        return GCD(b, a);
    if (a % b == 0)
        return b;
    return GCD(b, a % b);
}

long long int mod(long long int x1, long long int a)
{
    if (x1 >= 0)
        return x1 % a;
    else
        return x1 + a;
}

long long int modNghichDao(long long int a, long long int b)
{
    long long int u = b, v = a, x, x1 = 1, x2 = 0, q, r;
    while (u != 1)
    {
        q = v / u;
        r = v - q * u;
        x = x2 - q * x1;
        v = u;
        u = r;
        x2 = x1;
        x1 = x;
    }
    return mod(x1, a);
}

long long int nhanBinhPhuongCoLap(long long int a, long long int k, long long int n)
{
    long long int b = 1, A = a;
    if (k % 2 == 1)
        b = a;
    k /= 2;
    while (k > 0)
    {
        A = (A * A) % n;
        if (k % 2 == 1)
            b = (b * A) % n;
        k /= 2;
    }
    return b;
}

int main()
{
    srand(time(NULL));
    long long int p, q, e,SBD;
    printf("nhap SBD:");
    scanf("%lld", &SBD);
random:
    system("cls");
    while (1)
    { // random trong đoạn (100,500)
        p = 101 + rand() % (499 + 1 - 101);
        q = 101 + rand() % (499 + 1 - 101);
        if (ckeckSNT(p) == 1 && ckeckSNT(q) == 1 && p != q)
            break;
    }
    printf("p = %lld, q = %lld", p, q);
    long long int n = p * q, phi = (p - 1) * (q - 1);
    while (1)
    { // Chọn e (1 < e < phi(n))
        e = 2 + rand() % ((phi - 1) + 1 - 2);
        if (GCD(e, phi) == 1)
            break;
    }
    printf("\nn = %lld, phi = %lld, e = %lld", n, phi, e);

    // tính d = e^-1 mod phi(n)
    long long int d = modNghichDao(phi, e);
    printf("\nd = %lld^-1 mod %lld = %lld", e, phi, d);

    // Tính bản mã c của thông điệp m, với m = SBD + 123, c = m^e mod n
    long long int m = SBD + 123;
    if (n < m)
        goto random;
    printf("\nBan ro: m = %lld", m);
    long long int c = nhanBinhPhuongCoLap(m, e, n);
    printf("\nBan ma: c = %lld", c);

    // Giải mã thông điệp, tính m = c^d mod n
    long long int m1 = nhanBinhPhuongCoLap(c, d, n);
    printf("\nBan ro: m = %lld", m1);
}