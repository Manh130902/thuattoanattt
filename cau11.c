/*Viết chương trình tính tổng của các số nguyên tố nhỏ hơn hoặc bằng N với N được nhập từ bàn phím.*/
#include <stdio.h>
#include <math.h>
void sangSNT(long long int check[],long long int n)
{
    for (long long int i = 2; i <= n; i++)
    {
        check[i] = 1;
    }
    for (long long int i = 2; i <= n; i++)
    {
        if (check[i] == 1)
        {
            for (long long int j = 2 * i; j <= n; j += i)
            {
                check[j] = 0;
            }
        }
    }
}
int main()
{
    long long int n, tong = 0;
    scanf("%lld", &n);
    long long int check[n + 1]; // Sàng NT
    sangSNT(check,n+1);
    for (long long int i = 2; i <= n; i++)
    {
        if (check[i] == 1)
        {
            tong += i;
        }
    }
    printf("Tong cac so nguyen to nho hon bang N la: %lld", tong);
    return 0;
}