#include<stdio.h>
struct Process {
    int id, at, bt, pr, ct, tat, wt;
};

int main() {
    int n, current_time=0, completed=0,tq;
    float avgTat=0, avgWt=0;

    printf("Enter no. of process: ");
    scanf("%d",&n);
    struct Process P[n];
    int remaining[n];

    for(int i=0; i<n; i++) {
        P[i].id=i+1;
        printf("Enter arrival  and burst time for P%d: ",i+1);
        scanf("%d %d",&P[i].at, &P[i].bt);
        remaining[i]=P[i].bt;
    }

    printf("Assuming lowest no as highest priority\n");
    while(completed<n) {
        int executed=0;
        for(int i=0; i<n; i++) {
            if(P[i].at<=current_time && remaining[i]>0) {
                if(P[i].pr < highest) {
                    idx=i;
                }
            }
        }


    }
s
    printf("\nPID\tAT\tBT\tPR\tCT\tTAT\tWT\n");
    for(int i=0; i<n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", P[i].id, P[i].at, P[i].bt, P[i].pr, P[i].ct, P[i].tat, P[i].wt);
    }

    avgTat = avgTat/n;
    avgWt = avgWt/n;
    printf("\nAverage TAT: %f", avgTat);
    printf("\nAverage WT: %f",avgWt);

    return 0;
}


