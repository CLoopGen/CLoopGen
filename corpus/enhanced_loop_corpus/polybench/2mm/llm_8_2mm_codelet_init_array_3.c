#include <stdio.h>

#include <inttypes.h>

extern int ni;
extern int nk;
extern int nl;
extern double D[800][1200];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < ni; i++)
    for (j = 0; j < nl; j += 2) {
        double temp1 = (double)(i * (j + 2) % nk) / nk;
        double temp2 = (double)(i * (j + 3) % nk) / nk;
        D[i][j] = temp1;
        if (j + 1 < nl)
            D[i][j + 1] = temp2;
    }
}
