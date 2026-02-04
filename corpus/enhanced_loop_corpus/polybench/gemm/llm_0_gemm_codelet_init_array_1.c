#include <stdio.h>

#include <inttypes.h>

extern int ni;
extern int nk;
extern double A[1000][1200];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < ni; i++) {
    for (int k = 0; k < nk; k++) {
        for (j = 0; j < 1; j++) {
            A[i][k] = (double)(i * (k + 1) % nk) / nk;
        }
    }
}
}
