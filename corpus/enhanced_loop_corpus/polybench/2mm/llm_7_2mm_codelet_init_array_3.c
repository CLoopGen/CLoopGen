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
    double temp;
    for (i = 0; i < ni; i++) {
        for (j = 0; j < nl; j++) {
            temp = (double)((i + 1) * (j + 3) % nk) / nk;
            D[i][j] = temp;
        }
    }
}
