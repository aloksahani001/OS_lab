#include<stdio.h>

struct Process {
    int id, at, bt, type;
    int ct, tat, wt;
    int done;
};

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d",&n);

    struct Process P[n];
    for(int i=0;i<n;i++) {
        P[i].id = i+1;
        printf("Enter arrival and burst time for P%d: ",i+1);
        scanf("%d %d",&P[i].at,&P[i].bt);
        printf("Enter type (1-System, 2-User): ");
        scanf("%d",&P[i].type);
        P[i].done = 0;
    }
    int completed = 0, current_time = 0;
    int sumTat = 0, sumWt = 0;

    while(completed < n) {
        int idx = -1;
        int earliest = 9999;
        for(int i=0;i<n;i++) {
            if(P[i].type == 1 && P[i].done == 0 && P[i].at <= current_time) {
                if(P[i].at < earliest) {
                    earliest = P[i].at;
                    idx = i;
                }
            }
        }

        if(idx == -1) {
            earliest = 9999;
            for(int i=0;i<n;i++) {
                if(P[i].type == 2 && P[i].done == 0 && P[i].at <= current_time) {
                    if(P[i].at < earliest) {
                        earliest = P[i].at;
                        idx = i;
                    }
                }
            }
        }

        if(idx != -1) {
            if(current_time < P[idx].at)
                current_time = P[idx].at;
            current_time += P[idx].bt;

            P[idx].ct = current_time;
            P[idx].tat = P[idx].ct - P[idx].at;
            P[idx].wt = P[idx].tat - P[idx].bt;
            sumTat += P[idx].tat;
            sumWt += P[idx].wt;

            P[idx].done = 1;
            completed++;
        }
        else {
            current_time++;
        }
    }

    printf("\nPID\tAT\tBT\tType\tCT\tTAT\tWT\n");
    for(int i=0;i<n;i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        P[i].id,P[i].at,P[i].bt,P[i].type,
        P[i].ct,P[i].tat,P[i].wt);
    }

    printf("\nAverage TAT = %.2f",(float)sumTat/n);
    printf("\nAverage WT = %.2f",(float)sumWt/n);

    return 0;
}