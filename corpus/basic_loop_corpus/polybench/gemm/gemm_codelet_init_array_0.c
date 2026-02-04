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
    for (j = 0; j < nj; j++)
        C[i][j] = (double)((i * j + 1) % ni) / ni;

}
