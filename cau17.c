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

int main()
{
    int n, x, A, B, C;

    printf("Nhap so n: ");
    scanf("%d", &n);
    printf("Nhap A: ");
    scanf("%d", &A);
    printf("Nhap B: ");
    scanf("%d", &B);
    printf("Nhap C: ");
    scanf("%d", &C);
    for (x = 1; x < n; x++)
    {
        int T = A * x * x + B * x + C;
        if (check(T))
        {
            printf("%d la so nguyen to cua tong A.x^2+B.x+C=%d\n", x, T);
            break;
        }
        if ((check == 0) && (x == (n - 1)))
            printf("Khong co gia tri thoa man");
    }
}
