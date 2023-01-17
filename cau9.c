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
    int n, dem = 0;
    printf("nhap so N : ");
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        if (check(i))
        {
            //printf("%d    ", i);
            dem++;
        }
    }
    printf("\n co %d  so nguyen to", dem);
}