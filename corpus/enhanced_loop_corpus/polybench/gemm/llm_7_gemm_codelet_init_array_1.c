#include <stdio.h>

#include <inttypes.h>

extern int ni;
extern int nk;
extern double A[1000][1200];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
double temp;
for (i = 0; i < ni; i++) {
    temp = (double)(i % nk) / nk;
    for (j = 0; j < nk; j++) {
        A[i][j] = temp * (j + 1);
    }
}
}
