#include <stdio.h>
#include <string.h>

void F(char *P, int M, int *Fk)
{
    int len = 0;
    Fk[0] = 0;
    int i = 1;
    while (i < M)
    {
        if (P[i] == P[len])
        {
            len++;
            Fk[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = Fk[len - 1];
            }
            else
            {
                Fk[i] = 0;
                i++;
            }
        }
    }
}

void search(char *T, char *P)
{
    int M = strlen(P);
    int N = strlen(T);
    int Fk[M - 1];
    F(P, M - 1, Fk);
    int i = 0;
    int j = 0;
    int flag = 0;
    while (i < N)
    {

        if (P[j] == T[i])
        {
            i++;
            j++;
        }
        if (j == M)
        {
            printf("Su xuat hien cua mau \" %s \" trong van ban \" %s \" co vi tri bat dau la %d ", P, T, i - j);
            flag = 1;
            break;
        }
        else if (i < N && P[j] != T[i])
        {
            if (j == 0)
            {
                i = i + 1;
            }
            else
            {
                j = Fk[j - 1];
            }
        }
    }
    if (flag == 0)
    {
        printf("Mau \" %s \" khong xuat hien trong van ban \" %s \"", P, T);
    }
}
int main()
{
    char T[1000];
    char P[1000];

    printf("Nhap chuoi T : ");
    gets(T);
    printf("Nhap chuoi P : ");
    gets(P);

    search(T, P);
}