#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float **A;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 2; i < 4096; i++)
    for (j = 4; j < 4092; j++) {
        A[i][j] = A[i - 2][j + 4] * A[i - 1][j - 4] + 52;
    }

}
