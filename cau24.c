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
    else if (n == 2)
        return true;
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

int dem(int arr[], int n)
{
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                dem++;
            }
        }
    }
    return n - dem;
}

int main()
{
    int a, b, x = 0;
    printf("nhap a: ");
    scanf("%d", &a);
    printf("nhap b: ");
    scanf("%d", &b);
    int S1[b], S2[b];
    int t = 0;
    for (int i = 0; i < b; i++)
    {
        if (check(i))
        {
            S1[t] = i*i;
            S2[t] = i*i;
            t++;      
        }
        
    }
    for (int i = 0; i <= t; i++)
    {
        for (int j = i + 1; j <= t; j++)
        {
            int tong = S1[i] + S2[j];
            if (tong >= a && tong <= b && check(tong))
            {
                x++;
                printf("\n(%d,%d ) %d \n", S1[i], S2[j], tong);
            }
        }
    }
    printf("%d\n", x);
}