#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float **A;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 2; i < 4093; i++)
    for (j = 2; j < 4095; j++) {
        A[i][j] = A[i + 3][j - 2] + A[i - 2][j + 1] + 26;
    }

}
