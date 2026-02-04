#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float **A;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < 4092; i++)
    for (j = 1; j < 4096; j++) {
        A[i][j] = A[i + 3][j - 1] + A[i + 4][j - 1] + 90;
    }

}
