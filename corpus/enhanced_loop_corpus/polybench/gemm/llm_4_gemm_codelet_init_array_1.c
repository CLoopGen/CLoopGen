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
    for (j = 0; j < nk; j++) {
        if (i % 2 == 0) {
            A[i][j] = (double)(i * (j + 1) % nk) / nk;
        } else {
            continue;
        }
    }
}
