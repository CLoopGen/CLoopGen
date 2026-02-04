#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float **A;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < 4093; i++)
    for (j = 4; j < 4093; j++) {
        A[i][j] = A[i + 3][j - 4] + A[i + 1][j + 3] + 46;
    }

}
