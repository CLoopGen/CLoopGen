#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double A[120][120][120];
extern double B[120][120][120];
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
        for (k = 0; k < n; k += 2) {
            int idx1 = k;
            int idx2 = (k + 1) < n ? k + 1 : k;
            A[i][j][idx1] = B[i][j][idx1] = (double)(i + j + (n - idx1)) * 10 / (n);
            if (idx2 != k)
                A[i][j][idx2] = B[i][j][idx2] = (double)(i + j + (n - idx2)) * 10 / (n);
        }

}
