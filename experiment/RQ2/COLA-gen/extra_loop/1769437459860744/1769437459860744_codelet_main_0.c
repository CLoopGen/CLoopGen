#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float **A;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 4; i < 4094; i++)
    for (j = 5; j < 4096; j++) {
        A[i][j] = A[i + 2][j - 1] - A[i - 4][j - 5] + 1;
    }

}
