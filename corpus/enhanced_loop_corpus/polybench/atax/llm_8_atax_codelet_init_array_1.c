#include <stdio.h>

#include <inttypes.h>

extern int m;
extern int n;
extern double A[1900][2100];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < m; i++)
    for (j = 0; j < n; j += 2) {
        double temp1 = (double)((i + j) % n) / (5 * m);
        double temp2 = (j + 1 < n) ? (double)((i + j + 1) % n) / (5 * m) : temp1;
        A[i][j] = temp1;
        if (j + 1 < n)
            A[i][j + 1] = temp2;
    }
}
