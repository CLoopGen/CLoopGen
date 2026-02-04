#include <stdio.h>

#include <inttypes.h>

extern int ni;
extern int nk;
extern double A[800][1100];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp;
    for (i = 0; i < ni; i++) {
        for (j = 0; j < nk; j++) {
            temp = (double)((i + j) % nk) / nk;
            A[i][j] = temp * temp;
        }
    }
}
