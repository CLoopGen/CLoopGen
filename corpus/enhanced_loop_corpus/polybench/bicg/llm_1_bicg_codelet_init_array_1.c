#include <stdio.h>

#include <inttypes.h>

extern int m;
extern int n;
extern double A[2100][1900];
extern double r[2100];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n; i++) {
    r[i] = (double)(i % n) / n;
    for (j = 0; j < m; j++) {
        for (int k = 0; k < 1; k++) {
            A[i][j] = (double)(i * (j + 1) % n) / n;
        }
    }
}
}
