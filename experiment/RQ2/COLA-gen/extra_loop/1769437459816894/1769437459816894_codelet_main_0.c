#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float **A;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 4; i < 4093; i++)
    for (j = 0; j < 4095; j++) {
        A[i][j] = A[i + 3][j + 1] - A[i - 4][j + 1] + 41;
    }

}
