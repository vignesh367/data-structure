#include<stdio.h>
int main(){
    int a[4]={1,2,3,4};
    int b[4]={6,7,8,9};
    int c[8];
    int i,j;
    for(i=0;i<4;i++){
        c[i]=a[i];
    }
    for(i=0;i<4;i++){
        c[i+4]=b[i];
    }
    printf("{");
    for(i=0;i<8;i++){
        printf("%d,",c[i]);
    }
    printf("}");
}