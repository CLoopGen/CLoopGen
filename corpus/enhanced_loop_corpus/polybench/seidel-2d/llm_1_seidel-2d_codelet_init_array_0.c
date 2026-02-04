#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double A[2000][2000];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n; i++)
    for (int k = 0; k < n; k++)
        for (j = 0; j < 1; j++)
            A[i][k] = ((double)i * (k + 2) + 2) / n;
}
