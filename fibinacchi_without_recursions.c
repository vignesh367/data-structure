#include<stdio.h>
int main(){
    int a,i,b=0,c=1,n;
    printf("enter the value of a");
    scanf("%d",&a);
    if(a<0){
        printf("enter the valied number");
    }    
    else{
    for(i=1;i<=a;i++){
        printf("%d",b);
        n=b+c;
        b=c;
        c=n;
        printf("\n");
    }
    
    }
    
}