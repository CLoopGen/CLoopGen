#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double A[2000][2000];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n; i++) {
    double *Ai = A[i]; // Base pointer to row i for consecutive access
    for (j = 0; j <= i; j++)
        Ai[j] = (double)(-j % n) / n + 1;
    for (j = i + 1; j < n; j++) {
        Ai[j] = 0;
    }
    Ai[i] = 1;
}
}
