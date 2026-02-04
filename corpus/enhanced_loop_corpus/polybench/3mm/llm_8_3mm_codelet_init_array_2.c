#include <stdio.h>

#include <inttypes.h>

extern int nj;
extern int nl;
extern int nm;
extern double C[900][1200];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < nj; i++)
    for (j = 0; j < nm; j += 2)
        C[i][j] = (double)(i * (j + 3) % nl) / (5 * nl);
if (nm % 2 == 1)
    for (i = 0; i < nj; i++)
        C[i][nm - 1] = (double)(i * ((nm - 1) + 3) % nl) / (5 * nl);
}
