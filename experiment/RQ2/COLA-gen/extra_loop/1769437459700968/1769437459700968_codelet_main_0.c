#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float **A;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 2; i < 4091; i++)
    for (j = 1; j < 4096; j++) {
        A[j][i] = A[j - 1][i - 2] * A[j][i + 5] + 26;
    }

}
