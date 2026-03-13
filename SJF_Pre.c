#include <stdio.h>

struct Process {
    int id, at, bt, ct, tat, wt;
};

int main() {
    int n,current_time = 0, completed = 0;
    float avgTat=0, avgWt=0;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];
    int remaining[n];
    for(int i = 0; i < n; i++) {
        printf("Enter Arrival Time and Burst Time for P%d: ", i+1);
        scanf("%d %d", &p[i].at, &p[i].bt);
        p[i].id = i + 1;
        remaining[i] = p[i].bt;
    }

    while(completed < n) {
        int idx = -1;
        int min = 9999;
        for(int i = 0; i < n; i++) {
            if(p[i].at <= current_time && remaining[i] > 0) {
                if(remaining[i] < min) {
                    min = remaining[i];
                    idx = i;
                }
            }
        }

        if(idx != -1) {
            remaining[idx]--;
            current_time++;
            if(remaining[idx]==0) {
                p[idx].ct = current_time;
                p[idx].tat = p[idx].ct - p[idx].at;
                p[idx].wt = p[idx].tat - p[idx].bt;
                avgTat += p[idx].tat;
                avgWt += p[idx].wt;
                completed++;
            }
        } else {
            current_time++;
        }
    }

     printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i].id, p[i].at, p[i].bt,p[i].ct, p[i].tat, p[i].wt);
    }

    avgTat = avgTat/n;
    avgWt = avgWt/n;
    printf("\nAvg TAT : %f",avgTat);
    printf("\nAvg WT : %f",avgWt);

    return 0;
}
