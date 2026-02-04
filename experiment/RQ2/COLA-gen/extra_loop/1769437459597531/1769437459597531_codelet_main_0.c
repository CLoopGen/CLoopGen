#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float **A;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 1; i < 4092; i++)
    for (j = 1; j < 4096; j++) {
        A[j][i] = A[j][i - 1] - A[j - 1][i + 4] + 73;
    }

}
