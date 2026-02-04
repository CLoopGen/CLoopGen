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
    for (j = 4; j < 4093; j++) {
        A[i][j] = A[i][j - 4] * A[i + 4][j + 3] + 35;
    }

}
