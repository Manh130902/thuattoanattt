#include <stdio.h>
#include <math.h>
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

void nhapMang(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
}

void inMang(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%5d", a[i]);
    }
    printf("\n");
}

int main()
{
    int p, n, x;
    printf("Nhap p : ");
    scanf("%d", &p);
    printf("Nhap so phan tu mang : ");
    scanf("%d", &n);
    int a[n], b[n];
    nhapMang(a, n);
    for (int i = 0; i < n; i++)
    {
        if (gcd(a[i], p) == 1)
        {
            b[i] = tinh(a[i], p);
        }
        else
        {
            b[i] = 0;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (b[i] == 0)
        {
            printf("tren truong f%d thi %d ko co nghich dao\n", p, a[i]);
        }
        else
        {
            printf("tren truong f%d thi nghic dao cua %d la %d\n", p, a[i], b[i]);
        }
    }
}