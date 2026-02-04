#include <stdio.h>

#include <inttypes.h>

extern int ni;
extern int nk;
extern double A[1000][1200];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < nk; j++)
    for (i = 0; i < ni; i++) {
        int index = i * 1200 + j;
        *((double*)A + index) = (double)(i * (j + 1) % nk) / nk;
    }
}
