#include<stdio.h>
int main(){
    int a[100],n,i,b,c=0;
    int low,high,mid;
       
    printf("enter the value of n");
    scanf("%d",&n);
    printf("enter the sorted arrey elements");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);

    }
 printf("enter the value of b");
    scanf("%d",&b);
    low = 0;
    high = n + 1;
while(low<=high){
mid=(low+high)/2;
if(a[mid]==b){
    printf("the number found at index %d",mid);
    c=1;
    break;
}
else if(a[mid]<b){
    low=mid+1;
}
else{
    high=mid-1;
}

}
if(!c){
    printf("the number not found");
}
}