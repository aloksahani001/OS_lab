#include <stdio.h>

int n, m, p[99];

void disp(int f[]) {
    for (int i = 0; i < n; i++) f[i] == -1 ? printf("- ") : printf("%d ", f[i]);
    printf("\n");
}

void fifo() {
    int f[20], pf = 0, nxt = 0;
    for (int i = 0; i < n; i++) f[i] = -1;
    printf("\n--- FIFO ---\n");
    for (int i = 0; i < m; i++) {
        int hit = 0;
        for (int j = 0; j < n; j++) if (f[j] == p[i]) hit = 1;
        if (!hit) { f[nxt] = p[i]; nxt = (nxt + 1) % n; pf++; }
        printf("Page %d -> ", p[i]); disp(f);
    }
    printf("Total Page Faults: %d\n", pf);
}

void opt() {
    int f[20], pf = 0;
    for (int i = 0; i < n; i++) f[i] = -1;
    printf("\n--- OPTIMAL ---\n");
    for (int i = 0; i < m; i++) {
        int hit = 0;
        for (int j = 0; j < n; j++) if (f[j] == p[i]) hit = 1;
        if (!hit) {
            int rep = 0, far = -1;
            for (int j = 0; j < n; j++) {
                if (f[j] == -1) { rep = j; break; }
                int k;
                for (k = i + 1; k < m; k++) if (p[k] == f[j]) break;
                if (k > far) { far = k; rep = j; }
            }
            f[rep] = p[i]; pf++;
        }
        printf("Page %d -> ", p[i]); disp(f);
    }
    printf("Total Page Faults: %d\n", pf);
}

void lru() {
    int f[20], t[20] = {0}, pf = 0;
    for (int i = 0; i < n; i++) f[i] = -1;
    printf("\n--- LRU ---\n");
    for (int i = 0; i < m; i++) {
        int hit = -1;
        for (int j = 0; j < n; j++) if (f[j] == p[i]) hit = j;
        if (hit != -1) t[hit] = i;
        else {
            int rep = 0, min = 999;
            for (int j = 0; j < n; j++) {
                if (f[j] == -1) { rep = j; break; }
                if (t[j] < min) { min = t[j]; rep = j; }
            }
            f[rep] = p[i]; t[rep] = i; pf++;
        }
        printf("Page %d -> ", p[i]); disp(f);
    }
    printf("Total Page Faults: %d\n", pf);
}

int main() {
    printf("1BM24CS031\n");
    printf("Enter number of frames: "); scanf("%d", &n);
    printf("Enter number of pages: "); scanf("%d", &m);
    printf("Enter reference string: ");
    for (int i = 0; i < m; i++) scanf("%d", &p[i]);

    fifo();
    opt();
    lru();
    return 0;
}
