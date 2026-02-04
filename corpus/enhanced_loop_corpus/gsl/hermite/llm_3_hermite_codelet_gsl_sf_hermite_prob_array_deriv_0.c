#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int nmax;
extern double *result_array;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *indices = (int*)malloc((nmax + 1) * sizeof(int));
    for (int i = 0; i <= nmax; i++) {
        indices[i] = i;
    }
    for (j = 0; j <= nmax; j++) {
        int idx = indices[j]; // Indirect access via index array
        result_array[idx] = 0.;
    }
    free(indices);
}
