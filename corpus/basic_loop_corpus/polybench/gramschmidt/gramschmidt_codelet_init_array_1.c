#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double R[1200][1200];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
        R[i][j] = 0.;

}
