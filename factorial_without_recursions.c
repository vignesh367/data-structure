#include<stdio.h>
int main(){
    int a,i,b=1;
    printf("enter the value of a");
    scanf("%d",&a);
    for(i=1;i<=a;i++){
        b*=i;
    }
    printf("the factorial of %d is %d",a,b);
}