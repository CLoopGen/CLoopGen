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
    for (j = 5; j < 4096; j++) {
        A[i][j] = A[i + 2][j - 5] + A[i + 3][j - 5] + 11;
    }

}
