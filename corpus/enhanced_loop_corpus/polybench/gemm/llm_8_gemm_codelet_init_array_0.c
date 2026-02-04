#include <stdio.h>

#include <inttypes.h>

extern int ni;
extern int nj;
extern double C[1000][1100];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < ni; i++)
    for (j = 0; j < nj; j += 2) {
        double temp1 = (double)((i * j + 1) % ni) / ni;
        double temp2 = (double)((i * (j+1) + 1) % ni) / ni;
        C[i][j] = temp1;
        if (j+1 < nj)
            C[i][j+1] = temp2;
    }
}
