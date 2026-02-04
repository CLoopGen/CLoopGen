#include <stdio.h>

#include <inttypes.h>

extern int m;
extern int n;
extern double A[1900][2100];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < m; i++) {
    int temp_n = n;
    for (j = 0; j < temp_n; j++) {
        double val = (double)((i + j) % n);
        A[i][j] = val / (5 * m);
    }
}
}
