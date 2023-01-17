#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

int mod(int a, int b, int n)
{
    return ((a % n) * (b % n)) % n;
}

int nhanBinhPhuongCoLap(int a, int k, int n)
{
    int A = a, b = 1;
    if (k % 2 == 1)
        b = a;
    k /= 2;
    while (k > 0)
    {
        A = mod(A, A, n);
        if (k % 2 == 1)
            b = mod(b, A, n);
        k /= 2;
    }
    return b;
}

bool miller_rabin(int n)
{
    int s, r, trungGian = n - 1, j;
    while (trungGian % 2 != 1)
    {
        s++;
        trungGian /= 2;
        if (trungGian % 2 == 1)
            r = trungGian;
    }
    int a = 2 + rand() % (n - 3);

    int y = nhanBinhPhuongCoLap(a, r, n);

    if ((y != 1) && (y != n - 1))
    {
        j = 1;
        while ((j <= (s - 1)) && (y != n - 1))
        {
            y = (y * y) % n;
            if (y == 1)
            {
                return false;
            }
            j++;
        }
        if (y != n - 1)
        {
            return false;
        }
    }
    else
        return true;
}

void sort(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                int tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}
int find_min(int A[], int n)
{
    int value = A[n - 1];
    for (int i = 0; i < n - 1; i++)
    {
        int small = A[i + 1] - A[i];
        // b[i]= small;
        if (small < value)
            value = small;
    }
    return value;
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
    while (1)
    {
        srand(time(NULL));
        int n, x, min;
        printf("Nhap so phan tu cua mang :");
        scanf("%d", &n);
        int a[n];
        for (int i = 0; i < n; i++)
        {
            x = 2;
            while (miller_rabin(x) == false || x % 2 == 0)
            {
                x = rand() % 10000 + 3;
            }
            a[i] = x;
        }

        inMang(a, n);
        sort(a, n);
        // int z = find_min(a,n,b);
        inMang(a, n);
        // inMang(b,n-1);
        printf("\n%d", find_min(a, n));
        printf("\n");
    }
}