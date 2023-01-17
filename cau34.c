#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>


int nhanBinhPhuongCoLap(int a, int k, int n)
{
    int A = a, b = 1;
    if (k % 2 == 1)
        b = a;
    k /= 2;
    while (k > 0)
    {
        A =(A*A)%n;
        if (k % 2 == 1)
            b = (b*A)%n;
        k /= 2;
    }
    return b;
}
// TT fermat
int main()
{
    srand(time(NULL));
    int n, t, a, ran = 0, i, m;
input:
    printf("\nNhap n: ");
    scanf("%d", &n);
    if ((n < 3) | (n % 2 == 0))
    {
        printf("\nSo n la so le lon hon hoac bang 3; xin moi nhap lai.\n");
        goto input;
    }
    m = n;
    printf("\nSo lan lap:");
    scanf("%d", &t);
    for (i = 1; i <= t; i++)
    {
        printf("\n----------------\nLan lap %d", i);
        while (ran >= 0)
        {
            ran = rand()%10000;
            if ((ran >= 2) && (ran <= n - 2))
                break;
        }
        a = ran;
        printf("\n ran = %d", a);
        // da co n, so random a, tinh r = a^(n-1) mod n
        // tinh r bang pp nhan bp co lap
        int  x, A = a;
        x = n - 1; //=> tinh r = a^x (mod n)
        if (x == 0) 
        {
            printf("\nr = bn = 1");
        }
        printf("\nr = b= %d", nhanBinhPhuongCoLap(A, x, m)); // b la r = a^(n-1) mod n
        if (nhanBinhPhuongCoLap(A, x, m) != 1)
            printf("\nDay la hop so");
        else
            printf("\nDay la so nguyen to");
    }
}
