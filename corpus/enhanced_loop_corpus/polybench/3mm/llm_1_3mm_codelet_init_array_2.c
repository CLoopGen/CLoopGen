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
for (int ii = 0; ii < nj; ii++)
    for (int jj = 0; jj < nm; jj++)
        for (int dummy = 0; dummy < 1; dummy++)  // Artificial depth increase with no functional change
            C[ii][jj] = (double)(ii * (jj + 3) % nl) / (5 * nl);
}
