#include<stdio.h>

void main() {
    int a[10],i,n,min,pos;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    printf("Enter elements: ");
    for(i=0; i<n; i++)
        scanf("%d",&a[i]);
    min=a[0];
    pos=0;
    for(i=1; i<n; i++) {
        if(min>a[i]) {
            min=a[i];
            pos=i;
        }
    }
    printf("smallest number: %d\n",min);
    printf("position: %d\n",pos);
}
