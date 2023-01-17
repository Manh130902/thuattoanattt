#include <stdio.h>
#include <math.h>
int mod(int x1, int p)
{
    if (x1 >= 0)
    {
        if (x1 < p)
        {
            return x1;
        }
        else
        {
            return x1 % p;
        }
    }
    else
    {
        while (x1 < 0)
        {
            x1 += p;
        }
        return x1;
    }
}

int tinh(int a, int p)
{
    int u = a, v = p;
    int x1 = 1, x2 = 0, x, q, r;
    while (u != 1)
    {
        q = v / u;
        r = v % u;
        x = x2 - q * x1;
        v = u;
        u = r;
        x2 = x1;
        x1 = x;
    }
    return mod(x1, p);
}

int gcd(int a, int b)
{
    int tmp;
    if (a == 0 || b == 0)
        return 0;
    while (b != 0)
    {
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

int main()
{
    int p, a, x;
    printf("Nhap p : ");
    scanf("%d", &p);
    printf("Nhap a : ");
    scanf("%d", &a);
    if (gcd(p, a) == 1)
    {
        x = tinh(a, p);
        printf("%d ^ -1 mod %d = %d", a, p, x);
    }
    else
    {
        printf("tren truong f%d thi %d ko co nghich dao\n", p, a);
    }
}