#include <stdio.h>

#include <inttypes.h>

extern int nj;
extern int nk;
extern double B[1000][900];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < nk; i++)
    for (j = 0; j < nj; j++)
        B[i][j] = (double)((i * (j + 1) + 2) % nj) / (5 * nj);
// Introduce a WAW (Write-After-Write) dependency by updating the same element twice in sequence.
// This creates a loop-carried dependence on the write to B[i][j].
    for (i = 0; i < nk; i++)
        for (j = 0; j < nj; j++)
            B[i][j] = B[i][j] * B[i][j] + 0.1;
}
