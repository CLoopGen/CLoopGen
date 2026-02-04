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
    for (j = 0; j < nl; j++) {
        if ((i + j) % 2 == 0)
            D[i][j] = (double)((i * (j + 2) + 2) % nk) / (5 * nk);
        else
            continue;
    }
}
