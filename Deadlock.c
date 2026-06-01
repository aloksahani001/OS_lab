// #include<stdio.h>

// int main() {
//     int n, m;
//     printf("1BM24CS031\n");
//     printf("Enter number of processes: ");
//     scanf("%d",&n);
//     printf("Enter number of resource types: ");
//     scanf("%d",&m);
//     int allocation[n][m], request[n][m];
//     int available[m];

//     printf("Enter Allocation Matrix:\n");
//     for(int i=0;i<n;i++) {
//         for(int j=0;j<m;j++) {
//             scanf("%d",&allocation[i][j]);
//         }
//     }

//     printf("Enter Request Matrix:\n");
//     for(int i=0;i<n;i++) {
//         for(int j=0;j<m;j++) {
//             scanf("%d",&request[i][j]);
//         }
//     }

//     printf("Enter Available Matrix:\n");
//     for(int i=0;i<m;i++) {
//         scanf("%d",&available[i]);
//     }

//     int finish[n];
//     int work[m];
//     for(int i=0;i<m;i++)
//         work[i] = available[i];

//     for(int i=0;i<n;i++) {
//         int empty = 1;
//         for(int j=0;j<m;j++) {
//             if(allocation[i][j] != 0) {
//                 empty = 0;
//                 break;
//             }
//         }

//         if(empty)
//             finish[i] = 1;
//         else
//             finish[i] = 0;
//     }

//     while(1) {
//         int found = 0;
//         for(int i=0;i<n;i++) {
//             if(finish[i] == 0) {
//                 int possible = 1;
//                 for(int j=0;j<m;j++) {
//                     if(request[i][j] > work[j]) {
//                         possible = 0;
//                         break;
//                     }
//                 }

//                 if(possible) {
//                     for(int j=0;j<m;j++) {
//                         work[j] += allocation[i][j];
//                     }
//                     finish[i] = 1;
//                     found = 1;
//                 }
//             }
//         }

//         if(found == 0)
//             break;
//     }

//     int deadlock = 0;
//     for(int i=0;i<n;i++) {
//         if(finish[i] == 0) {
//             if(deadlock == 0)
//                 printf("\nDeadlock detected in processes:\n");
//             printf("P%d ",i);
//             deadlock = 1;
//         }
//     }

//     if(deadlock == 0)
//         printf("\nNo Deadlock detected");

//     return 0;
// }

#include <stdio.h>

int main() {
    int n, m, i, j, k, alloc[10][10], req[10][10], avail[10], f[10]={0}, ans[10], ind=0, flag;
    printf("1BM24CS031\n");
    printf("Enter the number of processes: "); scanf("%d", &n);
    printf("Enter the number of resources: "); scanf("%d", &m);

    printf("Enter the allocation matrix:\n");
    for(i=0; i<n; i++) for(j=0; j<m; j++) scanf("%d", &alloc[i][j]);

    printf("Enter the request matrix:\n");
    for(i=0; i<n; i++) for(j=0; j<m; j++) scanf("%d", &req[i][j]);

    printf("Enter the available resources:\n");
    for(j=0; j<m; j++) scanf("%d", &avail[j]);

    for(k=0; k<n; k++) {
        for(i=0; i<n; i++) {
            if(!f[i]) {
                flag=0;
                for(j=0; j<m; j++) {
                    if(req[i][j] > avail[j]) flag=1;
                }
                if(!flag) {
                    ans[ind++]=i;
                    for(j=0; j<m; j++) avail[j] += alloc[i][j];
                    f[i]=1;
                }
            }
        }
    }

    if(ind == n) {
        printf("System is in safe state.\nSafe Sequence is: ");
        for(i=0; i<n; i++) {
            printf("P%d%s", ans[i],  " ");
        }
    } else {
        printf("Deadlock Detected in the system!\n");
        printf("The deadlocked processes are: ");
        for(i=0; i<n; i++) {
            if(f[i] == 0) {
                printf("P%d ", i);
            }
        }
        printf("\n");
    }return 0;
}
