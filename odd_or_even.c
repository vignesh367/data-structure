#include<stdio.h>
int main(){
    int a[100],i,n,b,c=0,k;
    printf("enter the value of n");
    scanf("%d",&n);
    printf("enter the arrey elements");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);

    }
for(i=0;i<n;i++){
    if(a[i]%2==0){
        printf("%d=even\n",a[i],i);
    }
    else{
        printf("%d=odd\n",a[i],i);
    }
}

}