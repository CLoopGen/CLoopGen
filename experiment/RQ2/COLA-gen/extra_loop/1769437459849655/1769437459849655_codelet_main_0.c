#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float **A;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < 4095; i++)
    for (j = 2; j < 4092; j++) {
        A[j][i] = A[j - 2][i] - A[j + 4][i + 1] + 46;
    }

}
