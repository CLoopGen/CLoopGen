#include <stdio.h>

#include <inttypes.h>

extern int ni;
extern int nk;
extern double A[1000][1200];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < ni; i++)
    for (j = 0; j < nk; j += 2) {
        int idx1 = i * (j + 1) % nk;
        int idx2 = i * (j + 2) % nk;
        A[i][j] = (double)idx1 / nk;
        if (j + 1 < nk)
            A[i][j+1] = (double)idx2 / nk;
    }
}
