#include <stdio.h>
int main()
{
    long long int nho, p, q, i, N, j;
    int flag = 0;
    printf("Nhap so N duong : ");
    scanf("%lld", &N);

    for (j = 2; j < N; j++)
    {
        p = q = 0;
        nho = j;

        for (i = 1; i <= nho / 2; i++)
        {
            if (nho % i == 0)
            {
                p = p + i;
            }
        }

        for (i = 1; i <= p / 2; i++)
        {
            if (p % i == 0)
            {
                q = q + i;
            }
        }

        if (q == nho && p != q)
        {
            printf("Cap so do la: %lld  %lld\n", nho, p);
            flag = 1;
        }
    }
    if (flag == 0)
    {
        printf("khong co cap so nao\n");
    }
}
