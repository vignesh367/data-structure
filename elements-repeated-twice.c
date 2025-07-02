#include<stdio.h>
int main()
{
    int a[6]={1,2,3,4,5,3};
    int i,j,n,m,count=1;
    for(i=0;i<6;i++){
        for(j=i+1;j<6;j++){
            if(a[i]==a[j]){
                count++; 
                n=i;
                m=j;
            }
        }
    }
    printf("%d repeated %d times",a[n],count);
}