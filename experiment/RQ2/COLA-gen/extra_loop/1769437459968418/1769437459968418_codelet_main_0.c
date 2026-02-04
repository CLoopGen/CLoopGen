#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float **A;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 1; i < 4091; i++)
    for (j = 3; j < 4091; j++) {
        A[i][j] = A[i - 1][j + 5] * A[i + 5][j - 3] + 64;
    }

}
