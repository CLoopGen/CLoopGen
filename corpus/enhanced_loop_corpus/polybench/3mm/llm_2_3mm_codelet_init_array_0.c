#include <stdio.h>

#include <inttypes.h>

extern int ni;
extern int nk;
extern double A[800][1000];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < ni; i++)
    for (int k = 0; k < nk; k += 2)
        if (k + 1 < nk) {
            A[i][k]   = (double)((i * k       + 1) % ni) / (5 * ni);
            A[i][k+1] = (double)((i * (k + 1) + 1) % ni) / (5 * ni);
        } else {
            A[i][k] = (double)((i * k + 1) % ni) / (5 * ni);
        }
}
