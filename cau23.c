#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool check(int n)
{
    int d = 2;
    if (n == 0 || n == 1)
    {
        return false;
    }
    else
    {
        for (int i = 2; i <= sqrt(n); i++)
        {
            if (n % i == 0)
                d++;
        }
        return d == 2;
    }
}

int main()
{
    int a, b, tong = 0;
    printf("nhap a: ");
    scanf("%d", &a);
    printf("nhap b: ");
    scanf("%d", &b);
    for (int i = a; i <= b; i++)
    {
        if (check(i))
        {
            tong += i;
        }
    }
    if (check(tong))
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
}