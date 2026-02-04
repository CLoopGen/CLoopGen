#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float **A;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 3; i < 4096; i++)
    for (j = 3; j < 4091; j++) {
        A[i][j] = A[i - 3][j + 5] + A[i][j - 3] + 52;
    }

}
