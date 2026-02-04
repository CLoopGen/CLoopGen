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
    for (int k = 0; k < nk; k++) {
        j = k;
        A[i][j] = (double)((i * j + 1) % ni) / ni;
    }
}
}
