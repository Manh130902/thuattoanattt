#include <stdio.h>
#include <math.h>
#include <stdbool.h>
bool check(int n)
{
    if (n < 2)
        return false;
    else
    {
        for (int i = 2; i <= sqrt(n); i++)
        {
            if (n % i == 0)
                return false;
        }
        return true;
    }
}
int main()
{
    int a, b, i, tong = 0;
    printf("\nNhap A: ");
    scanf("%d", &a);
    printf("\nNhap B: ");
    scanf("%d", &b);
    while (a > b)
    {
        printf("\nNhap lai A: ");
        scanf("%d", &a);
        printf("\nNhap lai B: ");
        scanf("%d", &b);
    }
    if (b < 0)
    {
        printf("ko co so nguyen to nao trong khoang [%d,%d]\n", a, b);
    }
    else
    {
        for (i = a; i <= b; i++)
        {
            if (check(i))
            {
                tong += i;
            }
        }
        printf("so so nguyen to giua %d va %d la %d\n", a, b, tong);
    }
}
