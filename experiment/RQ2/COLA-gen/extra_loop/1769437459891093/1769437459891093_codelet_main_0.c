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
    for (j = 1; j < 4096; j++) {
        A[j][i] = A[j - 1][i - 3] - A[j - 1][i] + 23;
    }

}
