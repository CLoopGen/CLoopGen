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
for (i = 0; i < nm; i++)
    for (int k = 0; k < nk; k++)
        for (j = 0; j < nl; j++)
            D[i][j] = (double)((i * (j + 2) + 2) % nk) / (5 * nk);
}
