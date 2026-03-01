#include<stdio.h>

int LinearSearch(int a[10],int n,int ele) {
    for(int i=0; i<n; i++) {
        if(a[i]==ele) {
            return i;
        }
    }
    return -1;
}

int BinarySearch(int a[10],int n,int ele) {
    int low=0,high=n-1;
    int mid=(low+high)/2;
    while(mid>0) {
        if(a[mid]==ele) return mid;
        else if(ele<a[mid]) high=mid-1;
        else low=mid+1;
    }
    return -1;
}
void main() {
    int a[10],i,ele,n,pos;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    printf("Enter elements: ");
    for(i=0; i<n; i++)
        scanf("%d",&a[i]);
    printf("Enter search element: ");
    scanf("%d",&ele);

    pos=LinearSearch(a,n,ele);
    printf("Using linear search\n");
    if(pos==-1) printf("Search element not found\n");
    else printf("Element found at pos %d\n",pos);

    pos=BinarySearch(a,n,ele);
    printf("Using Binary search\n");
    if(pos==-1) printf("Search element not found\n");
    else printf("Element found at pos %d\n",pos);
}
