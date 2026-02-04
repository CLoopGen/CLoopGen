#include <stdio.h>

#include <inttypes.h>

extern int ni;
extern int nk;
extern double A[800][1100];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < ni; i++) {
    double temp = 0.0;
    for (j = 0; j < nk; j++) {
        temp = (double)((i * j * j + j + 1) % ni);
        A[i][j] = temp / ni * 0.5;
    }
}
}
