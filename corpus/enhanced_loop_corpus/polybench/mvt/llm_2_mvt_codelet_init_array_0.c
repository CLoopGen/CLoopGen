#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double x1[2000];
extern double x2[2000];
extern double y_1[2000];
extern double y_2[2000];
extern double A[2000][2000];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n; i++) {
    int idx = i;
    x1[idx] = (double)(i % n) / n;
    x2[idx] = (double)((i + 1) % n) / n;
    y_1[idx] = (double)((i + 3) % n) / n;
    y_2[idx] = (double)((i + 4) % n) / n;
    for (j = 0; j < n; j++) {
        int a_idx = i * 2000 + j; // Row-major linear index to ensure consecutive memory writes
        A[0][a_idx] = (double)(i * j % n) / n;
    }
}
}
