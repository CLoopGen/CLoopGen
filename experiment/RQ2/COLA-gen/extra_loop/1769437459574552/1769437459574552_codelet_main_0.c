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
    for (j = 5; j < 4095; j++) {
        A[j][i] = A[j - 5][i] * A[j + 1][i + 1] + 70;
    }

}
