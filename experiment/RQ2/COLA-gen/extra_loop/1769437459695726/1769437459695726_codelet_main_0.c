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
    for (j = 0; j < 4095; j++) {
        A[j][i] = A[j + 1][i + 3] - A[j][i + 1] + 51;
    }

}
