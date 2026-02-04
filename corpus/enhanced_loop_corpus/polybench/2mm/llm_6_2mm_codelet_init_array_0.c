#include <stdio.h>

#include <inttypes.h>

extern int ni;
extern int nk;
extern double A[800][1100];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < ni; i++) {
        for (j = 1; j < nk; j++) {
            A[i][j] = (double)((A[i-1][j-1] * 2.0) + 1.0) / ni;
        }
    }
}
