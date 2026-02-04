#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float **A;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < 4091; i++)
    for (j = 3; j < 4093; j++) {
        A[j][i] = A[j - 3][i + 3] * A[j + 3][i + 5] + 14;
    }

}
