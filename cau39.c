#include <stdio.h>
#include <math.h>
#include <stdbool.h>
bool checkSNT(long long int n)
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
void nhapMang(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        while (a[i] < 0)
        {
            printf("nhap lai a[%d]:", i);
            scanf("%d", &a[i]);
        }
    }
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
    int n;
    printf("nhap so phan tu: ");
    scanf("%d", &n);
    int a[n];
    nhapMang(a, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int x = gcd(a[i], a[j]);
            if (checkSNT(x))
            {
                printf("(%d,%d)\n", a[i], a[j]);
            }
        }
    }
}