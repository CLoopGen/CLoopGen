#include <stdio.h>

#include <inttypes.h>

extern int ni;
extern int nk;
extern double A[800][1000];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < ni && j < nk; i++)
    A[i][j] = (double)((i * j + 1) % ni) / (5 * ni);
j++;
if (j < nk) {
    i = 0;
    A[0][j] = (double)((0 * j + 1) % ni) / (5 * ni);
    for (i = 1; i < ni; i++)
        A[i][j] = (double)((i * j + 1) % ni) / (5 * ni);
}
}
