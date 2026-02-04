#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float **A;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < 4094; i++)
    for (j = 3; j < 4094; j++) {
        A[i][j] = A[i + 1][j - 3] - A[i + 2][j + 2] + 55;
    }

}
