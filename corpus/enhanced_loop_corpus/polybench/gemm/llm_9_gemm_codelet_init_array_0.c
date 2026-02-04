#include <stdio.h>

#include <inttypes.h>

extern int ni;
extern int nj;
extern double C[1000][1100];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < ni; i++)
    for (j = 0; j < nj; j++) {
        double idx = (double)(i * j);
        double val = (idx + 1.0) / ni;
        val = (val >= 1.0) ? val - (int)val : val;
        C[i][j] = val;
    }
}
