#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *lut;
extern int N;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *indices = (int*)malloc(N * sizeof(int));
    for (n = 0; n < N; n++)
        indices[n] = n;
    for (n = 0; n < N; n++)
        lut[indices[n]] = 1.;
    free(indices);
}
