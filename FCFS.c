#include<stdio.h>

struct Process {
    int id, at, bt, ct, tat, wt;
};

void main() {
    int n,current_time=0;
    int sumTat=0, sumWt=0;
    printf("Enter no. of process: ");
    scanf("%d",&n);
    struct Process P[n];
    for(int i=0; i<n; i++) {
        printf("Enter process id: ");
        scanf("%d",&P[i].id);
        printf("Enter arrival time: ");
        scanf("%d",&P[i].at);
        printf("Enter burst time: ");
        scanf("%d",&P[i].bt);
    }

    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            if(P[i].at>P[j].at) {
                struct Process temp=P[i];
                P[i]=P[j];
                P[j]=temp;
            }
        }
    }

    for(int i=0; i<n; i++) {
        if(current_time<P[i].at)
            current_time=P[i].at;
        P[i].ct=current_time+P[i].bt;
        P[i].tat=P[i].ct-P[i].at;
        P[i].wt=P[i].tat-P[i].bt;
        current_time=P[i].ct;
        sumTat+= P[i].tat;
        sumWt+= P[i].wt;
    }

    printf("PID\tAT \tBT \tCT \tTAT \tWT\n");
    for(int i=0; i<n; i++) {
        printf("%d \t%d \t%d \t%d \t%d \t%d \n",P[i].id,P[i].at,P[i].bt,P[i].ct,P[i].tat,P[i].wt);
    }
    float avgTat= (float)sumTat/n;
    float avgWt= (float)sumWt/n;
    printf("Average TAT time: %f\n",avgTat);
    printf("Average WT time: %f\n",avgWt);
}
