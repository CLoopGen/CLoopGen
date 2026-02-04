#include <stdio.h>

#include <inttypes.h>

extern int m;
extern int n;
extern double A[1000][1000];
extern double B[1000][1200];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < m; i++) {
    for (j = 0; j <= i; j++) {
        if (j < i) {
            double temp = (double)((i * i + j * j) % m);
            A[i][j] = temp / m;
        } else {
            A[i][j] = 1.;
        }
    }
    for (j = 0; j < n; j += 4) {
        B[i][j] = (double)((n + (i - j)) % n) / n;
        if (j + 1 < n) B[i][j+1] = (double)((n + (i - (j+1))) % n) / n;
        if (j + 2 < n) B[i][j+2] = (double)((n + (i - (j+2))) % n) / n;
        if (j + 3 < n) B[i][j+3] = (double)((n + (i - (j+3))) % n) / n;
    }
}
}
