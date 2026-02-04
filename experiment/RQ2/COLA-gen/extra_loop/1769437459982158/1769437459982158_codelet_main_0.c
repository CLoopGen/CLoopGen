#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float **A;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 2; i < 4096; i++)
    for (j = 3; j < 4094; j++) {
        A[j][i] = A[j + 2][i] - A[j - 3][i - 2] + 5;
    }

}
