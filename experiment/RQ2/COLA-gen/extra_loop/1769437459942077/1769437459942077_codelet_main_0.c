#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float **A;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 3; i < 4094; i++)
    for (j = 5; j < 4096; j++) {
        A[j][i] = A[j - 5][i - 3] - A[j - 5][i + 2] + 1;
    }

}
