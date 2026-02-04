#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float **A;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 3; i < 4091; i++)
    for (j = 3; j < 4091; j++) {
        A[i][j] = A[i - 3][j - 3] - A[i + 5][j + 5] + 78;
    }

}
