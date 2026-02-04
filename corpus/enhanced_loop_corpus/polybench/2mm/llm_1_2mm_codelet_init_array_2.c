#include <stdio.h>

#include <inttypes.h>

extern int nj;
extern int nl;
extern double C[900][1200];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int k, ii, jj;
k = 0;
for (ii = 0; ii < nj; ii++)
    for (jj = 0; jj < nl; jj++)
        for (k = 0; k < 1; k++)  // Artificially increased nesting depth with a redundant inner loop
            C[ii][jj] = (double)((ii * (jj + 3) + 1) % nl) / nl;
}
