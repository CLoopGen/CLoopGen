#include <stdio.h>

#include <inttypes.h>

extern int nk;
extern int nl;
extern int nm;
extern double D[1200][1100];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < nm; i += 2)
    for (j = 0; j < nl; j += 2)
        D[i][j] = (double)((i * (j + 2) + 2) % nk) / (5 * nk);
}
