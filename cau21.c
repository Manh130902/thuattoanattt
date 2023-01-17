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

int demSNT(int n)
{
    int dem = 0;
    for (int i = 2; i < n; i++)
    {
        if (check(i))
        {
            dem++;
        }
    }
    return dem;
}

int main()
{
    int a, b;
    int dem = 0;
    printf("nhap A: ");
    scanf("%d", &a);
    printf("nhap B: ");
    scanf("%d", &b);
    for (int i = a; i <= b; i++)
    {
        if (check(demSNT(i)))
        {
            printf("%5d", i);
            dem++;
        }
    }
    printf("\nso so sieu nguyen to trong khoang [%d, %d] la: %d\n", a, b, dem);
    return 0;
}