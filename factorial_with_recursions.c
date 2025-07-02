#include<stdio.h>
int rec(int a){
if(a==0||a==1){
    return 1;
}
return a*rec(a-1);
}
int main(){
    int a;
    printf("enter the value of a");
    scanf("%d",&a);
    
    printf("the factorial of %d is %d",a,rec(5));
}