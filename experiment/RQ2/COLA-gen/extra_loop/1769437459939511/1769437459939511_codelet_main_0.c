#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float **A;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 1; i < 4094; i++)
    for (j = 0; j < 4092; j++) {
        A[j][i] = A[j + 4][i + 2] * A[j + 4][i - 1] + 59;
    }

}
