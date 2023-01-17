#include <stdio.h>
#include <string.h>

int LastOccurrence(char *P, char x)
{
    int i;
    for (i = strlen(P) - 1; i >= 0; i--)
    {
        if (P[i] == x)
        {
            return i;
        }
    }
    return -1;
}

void search(char *T, char *P)
{
    int m = strlen(P);
    int i = m - 1;
    int j = m - 1;
    int min;
    int flag = 0;
    while (i < strlen(T))
    {
        if (T[i] != P[j])
        {
            if (j < 1 + LastOccurrence(P, T[i]))
            {
                min = j;
            }
            else
            {
                min = 1 + LastOccurrence(P, T[i]);
            }
            i = i + m - min;
            j = m - 1;
        }
        else
        {
            if (j == 0)
            {
                printf("Su xuat hien cua mau \"%s\" trong van ban \"%s\" co vi tri bat dau la %d", P, T, i);
                flag = 1;
                break;
            }
            i--;
            j--;
        }
    }
    if (flag == 0)
    {
        printf("Mau \"%s\" khong xuat hien trong van ban \"%s\"", P, T);
    }
}
int main()
{
    char T[1000], P[1000];
    printf("nhap chuoi T :");
    gets(T);
    printf("nhap chuoi P :");
    gets(P);
    search(T, P);
}