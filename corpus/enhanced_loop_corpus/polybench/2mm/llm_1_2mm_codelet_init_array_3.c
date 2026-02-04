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
for (i = 0; i < ni && j < nl; i++, j++)
    D[i][j] = (double)(i * (j + 2) % nk) / nk;
if (i < ni)
    for (; i < ni; i++)
        D[i][nl-1] = (double)(i * ((nl-1) + 2) % nk) / nk;
if (j < nl)
    for (; j < nl; j++)
        D[ni-1][j] = (double)((ni-1) * (j + 2) % nk) / nk;
}
