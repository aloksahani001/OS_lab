#include<stdio.h>

struct Process {
    int id, at, bt, ct, tat, wt, remaining;
};

int main() {
    int n, tq, completed = 0, current_time = 0;
    float avgTat = 0, avgWt = 0;

    printf("Enter number of processes: ");
    scanf("%d",&n);
    struct Process P[n];

    for(int i=0;i<n;i++) {
        P[i].id = i+1;
        printf("Enter arrival and burst time for P%d: ",i+1);
        scanf("%d %d",&P[i].at,&P[i].bt);
        P[i].remaining = P[i].bt;
    }
    printf("Enter Time Quantum: ");
    scanf("%d",&tq);

    for(int i=0;i<n-1;i++) {
        for(int j=i+1;j<n;j++) {
            if(P[i].at > P[j].at) {
                struct Process temp = P[i];
                P[i] = P[j];
                P[j] = temp;
            }
        }
    }

    int queue[100], front = 0, rear = 0;
    int visited[n];
    for(int i=0;i<n;i++)
        visited[i] = 0;
    queue[rear++] = 0;
    visited[0] = 1;

    while(completed < n) {
        int idx = queue[front++];
        if(current_time < P[idx].at)
            current_time = P[idx].at;

        int exec = (P[idx].remaining > tq) ? tq : P[idx].remaining;
        P[idx].remaining -= exec;
        current_time += exec;

        for(int i=0;i<n;i++) {
            if(visited[i] == 0 && P[i].at <= current_time) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }

        if(P[idx].remaining > 0) {
            queue[rear++] = idx;
        }
        else {
            P[idx].ct = current_time;
            P[idx].tat = P[idx].ct - P[idx].at;
            P[idx].wt = P[idx].tat - P[idx].bt;
            avgTat += P[idx].tat;
            avgWt += P[idx].wt;

            completed++;
        }

        if(front == rear) {
            for(int i=0;i<n;i++) {
                if(visited[i] == 0) {
                    queue[rear++] = i;
                    visited[i] = 1;
                    current_time = P[i].at;
                    break;
                }
            }
        }
    }

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i=0;i<n;i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
        P[i].id,P[i].at,P[i].bt,P[i].ct,P[i].tat,P[i].wt);
    }
    avgTat = avgTat/n;
    avgWt = avgWt/n;
    printf("\nAverage TAT = %f",avgTat);
    printf("\nAverage WT = %f",avgWt);

    return 0;
}