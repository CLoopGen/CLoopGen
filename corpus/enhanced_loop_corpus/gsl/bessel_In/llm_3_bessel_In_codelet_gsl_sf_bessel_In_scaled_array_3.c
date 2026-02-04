#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int nmin;
extern  int nmax;
extern double *result_array;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *indices = (int*)malloc((nmax - nmin + 1) * sizeof(int));
    if (!indices) return;
    for (int i = 0; i <= nmax - nmin; i++) {
        indices[i] = i; // Indirect access via index array
    }
    for (j = 0; j <= nmax - nmin; j++) {
        result_array[indices[j]] = 0.;
    }
    free(indices);
}
