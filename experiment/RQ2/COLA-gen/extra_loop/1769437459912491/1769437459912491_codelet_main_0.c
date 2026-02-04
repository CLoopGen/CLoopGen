#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float **A;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 3; i < 4095; i++)
    for (j = 3; j < 4095; j++) {
        A[i][j] = A[i + 1][j - 3] * A[i - 3][j + 1] + 52;
    }

}
