#include <stdio.h>

#define MAX 100

void firstFit(int blocks[], int m, int processes[], int n) {
    int allocation[MAX];

    for (int i = 0; i < n; i++)
        allocation[i] = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (blocks[j] >= processes[i]) {
                allocation[i] = j;
                blocks[j] = -1;
                break;
            }
        }
    }

    printf("\nFIRST FIT ALLOCATION\n");
    printf("Process No\tProcess Size\tBlock No\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i + 1, processes[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

void bestFit(int blocks[], int m, int processes[], int n) {
    int allocation[MAX];
    for (int i = 0; i < n; i++)
        allocation[i] = -1;

    for (int i = 0; i < n; i++) {
        int best = -1;
        for (int j = 0; j < m; j++) {
            if (blocks[j] >= processes[i]) {
                if (best == -1 || blocks[j] < blocks[best]) {
                    best = j;
                }
            }
        }

        if (best != -1) {
            allocation[i] = best;
            blocks[best] = -1;
        }
    }

    printf("\nBEST FIT ALLOCATION\n");
    printf("Process No\tProcess Size\tBlock No\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i + 1, processes[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

void worstFit(int blocks[], int m, int processes[], int n) {
    int allocation[MAX];
    for (int i = 0; i < n; i++)
        allocation[i] = -1;
    for (int i = 0; i < n; i++) {
        int worst = -1;
        for (int j = 0; j < m; j++) {
            if (blocks[j] >= processes[i]) {
                if (worst == -1 || blocks[j] > blocks[worst]) {
                    worst = j;
                }
            }
        }

        if (worst != -1) {
            allocation[i] = worst;
            blocks[worst] = -1;
        }
    }

    printf("\nWORST FIT ALLOCATION\n");
    printf("Process No\tProcess Size\tBlock No\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i + 1, processes[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

int main() {
    int m, n;
    printf("ALOK SAHANI\n1BM24CS031\n");
    printf("Enter number of memory blocks: ");
    scanf("%d", &m);
    int blocks[MAX], blocks1[MAX], blocks2[MAX];

    printf("Enter sizes of memory blocks:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &blocks[i]);
        blocks1[i] = blocks[i];
        blocks2[i] = blocks[i];
    }

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int processes[MAX];
    printf("Enter sizes of processes:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &processes[i]);
    }

    firstFit(blocks, m, processes, n);
    bestFit(blocks1, m, processes, n);
    worstFit(blocks2, m, processes, n);

    return 0;
}
