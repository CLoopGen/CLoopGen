#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float **A;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 1; i < 4095; i++)
    for (j = 2; j < 4096; j++) {
        A[i][j] = A[i - 1][j - 1] + A[i + 1][j - 2] + 53;
    }

}
