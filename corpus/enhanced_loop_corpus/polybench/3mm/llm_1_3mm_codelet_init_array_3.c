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
for (i = 0; i < nm && j < nl; i++, j++)
    D[i][j] = (double)((i * (j + 2) + 2) % nk) / (5 * nk);
if (i < nm)
    for (; i < nm; i++)
        D[i][nl-1] = (double)((i * ((nl-1) + 2) + 2) % nk) / (5 * nk);
if (j < nl)
    for (; j < nl; j++)
        D[nm-1][j] = (double)(((nm-1) * (j + 2) + 2) % nk) / (5 * nk);
}
