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
double temp_r[2100];
for (i = 0; i < n; i++) {
    temp_r[i] = (double)(i % n) / n;
    for (j = 0; j < m; j++) {
        A[i][j] = (double)((i + 1) * (j + 1) % n) / n;
    }
}
for (i = 0; i < n; i++) {
    r[i] = temp_r[i];
}
}
