#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float **A;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 4; i < 4091; i++)
    for (j = 2; j < 4096; j++) {
        A[j][i] = A[j - 2][i + 5] + A[j][i - 4] + 48;
    }

}
