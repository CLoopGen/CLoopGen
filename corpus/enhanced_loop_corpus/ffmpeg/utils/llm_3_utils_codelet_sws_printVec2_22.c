#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct SwsVector {
    double *coeff;
    int length;
} SwsVector;

extern SwsVector *a;
extern int i;
extern double min;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *indices = (int*)malloc(a->length * sizeof(int));
    for (i = 0; i < a->length; i++)
        indices[i] = i;
    for (i = 0; i < a->length; i++) {
        int idx = indices[i];
        if (a->coeff[idx] < min)
            min = a->coeff[idx];
    }
    free(indices);
}
