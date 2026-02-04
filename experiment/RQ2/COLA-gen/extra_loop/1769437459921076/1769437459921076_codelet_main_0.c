#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float **A;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 5; i < 4096; i++)
    for (j = 2; j < 4095; j++) {
        A[i][j] = A[i - 5][j - 2] + A[i][j + 1] + 53;
    }

}
