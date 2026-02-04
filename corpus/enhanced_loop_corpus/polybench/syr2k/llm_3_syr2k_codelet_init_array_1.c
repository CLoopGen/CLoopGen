#include <stdio.h>

#include <inttypes.h>

extern int n;
extern int m;
extern double C[1200][1200];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n * n; i += 2) {
    int i1 = i / n, j1 = i % n;
    int i2 = (i + 1) / n, j2 = (i + 1) % n;
    C[i1][j1] = (double)((i1 * j1 + 3) % n) / m;
    if (i + 1 < n * n) {
        C[i2][j2] = (double)((i2 * j2 + 3) % n) / m;
    }
}
}
