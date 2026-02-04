#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float **A;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 5; i < 4094; i++)
    for (j = 0; j < 4093; j++) {
        A[j][i] = A[j][i + 2] + A[j + 3][i - 5] + 72;
    }

}
