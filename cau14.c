//Viết chương trình tìm số nguyên tố có ba chữ số, biết rằng nếu viết số đó theo thứ tự 
//ngược lại thì ta được một số là lập phương của một số tự nhiên.
#include<stdio.h>
#include<math.h>
#include<stdbool.h>
int sodaonguoc(long long int n){
   long long int res = 0;
    while(n > 0){
        long long int tmp = n % 10;
        res = res * 10 + tmp;
        n = n / 10;
    }
    return res;
}

bool check(long long int n)
{
    int d=2;
    if(n==0 || n==1){
        return false;
    }else{
        for(long long int i = 2; i <= sqrt(n); i++)
        {
            if(n % i == 0)
                d++;
        }
        return d==2;
    }
    
}

int main()
{
	for(int i = 100; i < 1000; i++)
	{
		int res = 0;
		int tmp;
		if(check(i)==true)
		{
			int daoNguoc = sodaonguoc(i);
			for(int z = 1; z <= sqrt(daoNguoc); z++)
			{
				if(z * z * z == daoNguoc)
				{
 				    printf("Vay so can tim la %d va lap phuong cua no la: %d", i, daoNguoc);
				}
			}
		}
	}
}
