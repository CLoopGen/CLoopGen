#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float **A;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 4; i < 4093; i++)
    for (j = 3; j < 4096; j++) {
        A[j][i] = A[j - 3][i + 3] + A[j][i - 4] + 57;
    }

}
