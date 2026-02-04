#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float **A;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 2; i < 4093; i++)
    for (j = 4; j < 4091; j++) {
        A[j][i] = A[j - 4][i + 3] - A[j + 5][i - 2] + 2;
    }

}
