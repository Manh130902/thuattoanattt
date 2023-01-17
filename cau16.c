#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

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
void nhapMang(int a[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        a[i] = rand() % 10 + 3;
    }
}

void inMang(int a[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        printf("%5d", a[i]);
    }
    printf("\n");
}

int main()
{
    int arr[100], n;
    srand(time(NULL));
    printf("nhap so phan tu: ");
    scanf("%d", &n);
    nhapMang(arr, n);
    inMang(arr, n);
    for (int i = 0; i < n; ++i)
    {
        if (check(arr[i]))
        {
            printf("arr[%d] = %d\n", i, arr[i]);
        }
    }
}