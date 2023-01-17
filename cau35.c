#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
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
int main()
{
    srand(time(NULL));
    int n, t, i;
    label:
    printf("\nNhap n: ");
    scanf("%d", &n);
    if ((n < 3) | (n % 2 == 0))
    {
        printf("\nSo n la so le lon hon hoac bang 3; xin moi nhap lai.\n");
        goto label;
    }
    printf("So lan lap: ");
    scanf("%d", &t);
    // Tim r va s thoa man n-1 = r*2^s
    int r, s, trunggian;
    trunggian = n - 1;
    r = trunggian;
    s = 0;
    while (r > 0)
    {
        if (r % 2 == 1)
        {
            printf("\ns = %d; r = %d", s, r);
            break;
        }
        r = trunggian / 2;
        trunggian = r;
        s++;
    }
    for (i = 1; i <= t; i++)
    {
        // Chon random so ng a, 2=< a <= n-2
        int a, j;
        printf("\n-------------\nLan lap %d", i);
        a = 2 + rand() % (n - 3);
        printf("\na = %d\n", a);
        // Dung nhan bp co lap de tinh y = a^r mod n
        a = 2;
        printf("\ny = b = %d", nhanBinhPhuongCoLap(a, r, n));
        int y = nhanBinhPhuongCoLap(a, r, n);
        if ((y != 1) && (y != n - 1))
        {
            j = 1;
            while ((j <= (s - 1)) && (y != n - 1))
            {
                y = (y * y) % n;
                if (y == 1)
                {
                    printf("\nHop so.");
                    // return 1;
                }
                j++;
            }
            if (y != n - 1)
            {
                printf("\nHop so.");
                // return 1;
            }
            else
                printf("\nSo nguyen to.");
        }
        else
            printf("\nSo nguyen to.");
    }
}
