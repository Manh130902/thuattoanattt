#include <stdio.h>
#include <math.h>
int kiemtratinhgnuyento(int m)
{
    if (m == 0 || m == 1)
        return 0;
    if (m == 2)
        return 1;
    for (int k = 2; k <= sqrt(m); k++)
    {
        if (m % k == 0)
            return 0;
    }
    return 1;
}

int result(int l, int r)
{
    int sum = 0;
    for (int i = l; i < r; i++)
    {
        int fi = 0;
        if (kiemtratinhgnuyento(i))
        {
            fi = i;
        }
        else
        {
            fi = 0;
        }
        for (int j = i + 1; j < r + 1; j++)
        {
            int fj = 0;
            if (kiemtratinhgnuyento(j))
            {
                fj = j;
            }
            else
            {
                fj = 0;
            }
            sum += fi * fj;
        }
    }
    return sum;
}
int main()
{
    int L, R;
    printf("nhap L: ");
    scanf("%d", &L);
    printf("nhap R: ");
    scanf("%d", &R);
    while (L >= R)
    {
        printf("nhap lai R: ");
        scanf("%d", &R);
    }
    printf("%d", result(L, R));
    return 0;
}