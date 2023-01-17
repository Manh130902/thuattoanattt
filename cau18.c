#include<stdio.h>
#include<math.h>

void chuyenSoNguyenLon(int arr[100],long long int p,int W,int a,int t)
{
    for(int i = t-1 ; i>=0; i--)
    {
        long long int z = pow(2,W*i);
        arr[i]=a/z;
        a = a%z;
    }

}

int cong(int a[100],int b[100],int c[100],int t,int W)
{
    int e = 0;
    for(int i =0; i<t; i++)
    {
        int w=a[i]+b[i]+e;
        int h = pow(2,W);
        if(w>=h)
        {
            e=1;
            c[i]=w%h;
        }
        else
        {
            e=0;
            c[i]=w%h;
        }
    }
    return e;
}
int tru(int a[100],int b[100],int c[100],int t,int W)
{
    int e = 0;
    for(int i =0; i<t; i++)
    {
        int w=a[i]-b[i]-e;
        int h = pow(2,W);
        if(w<0)
        {
            c[i]=h+w;
            e=1;
        }
        else if(w>=h)
        {
            c[i] =w%h;
            e=1;
        }
        else
        {
            e=0;
            c[i]=w%h;
        }
    }
     
    return e;
}

void inMang(int Mang[],int t){
printf("[");
    for(int i = t-1 ; i >=0 ; i--)
    {
        printf("%d",Mang[i]);
        if(i!=0)
        {
            printf("   ");
        }
        else
        {
            printf("]\n");
        }
    }
}

void chuyenVeSoNguyenLon( int arr[100],long long int p ,int W)
{
    int m = ceil(log(p)/log(2));
    int t = ceil((float)m/W);
    long long int a = 0;
   for(int i=t-1 ; i>=0; i--)
    {
        long long int z = pow(2,W *(i));
        a += arr[i]*z;
    }
    printf("\nSo do La: %lld", a);
}
int main()
{
    int arr[100],brr[100],c[100],P[100],W=8,m,t,e,i;
    long long int p=2147483647,a,b;
    scanf("%lld%lld",&a,&b);
    m = ceil(log(p)/log(2));
    t = ceil((float)m/W);
    chuyenSoNguyenLon(arr,p,W,a,t);
    chuyenSoNguyenLon(brr,p,W,b,t);
    chuyenSoNguyenLon(P,p,W,p,t);
    printf("--------------------------------\n");
    printf("Ma tran cua P:\n");
    inMang(P,t);
    e = cong(arr,brr,c,t,W);
    if(e==1)
    {
        tru(c,P,c,t,W);
    }
    else
    {
        for(i = t-1 ; i >= 0 ; i--)
        {
            if(c[i]==P[i]&&i!=0)
            {
                continue;
            }
            else if(c[i]>=P[i])
            {
                tru(c,P,c,t,W);
                break;
            }
            else
            {
                break;
            }
        }
    }


printf("Ket qua cong tren truong huu han:\n");
inMang(c,t);
chuyenVeSoNguyenLon(c,p,W);
}
