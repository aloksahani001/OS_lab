#include<stdio.h>

void main() {
    int a[10],i,j,n,flag=0;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    printf("Enter elements: ");
    for(i=0; i<n; i++)
        scanf("%d",&a[i]);

    for(i=0; i<n; i++) {
        for(j=i+1; j<n; j++) {
            if(a[i]==a[j]) {
                flag=1;
                break;
            }
        }
    }

    if(flag) printf("duplicates are present");
    else printf("duplicates are not present");
}
