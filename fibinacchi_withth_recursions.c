#include<stdio.h>
int fib(int x){

        if(x==0){
            return 0;
        }
        else if(x==1){
            return 1;
}
        else{
        return fib(x-1)+fib(x-2);}

    
        }
int main(){
    int a=6,i,b=8;
     if(a<0){
        printf("the number entered is invalied");
        return 1;
            }
    for(i=1;i<=b;i++){
        printf("%d\t",fib(i));
    }
}