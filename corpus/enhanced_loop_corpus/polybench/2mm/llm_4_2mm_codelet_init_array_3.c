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
    for (j = 0; j < nl; j++) {
        if (i % 2 == 0) {
            D[i][j] = (double)(i * (j + 2) % nk) / nk;
        } else {
            D[i][j] = 0.0;
        }
    }
}
