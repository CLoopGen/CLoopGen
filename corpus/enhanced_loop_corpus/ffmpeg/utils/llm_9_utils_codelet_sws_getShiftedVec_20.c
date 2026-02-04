#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct SwsVector {
    double *coeff;
    int length;
} SwsVector;

extern SwsVector *a;
extern int shift;
extern int length;
extern int i;
extern SwsVector *vec;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int offset = (length - 1) / 2 - (a->length - 1) / 2 - shift;
    int trip_count = a->length * 3;
    for (i = 0; i < trip_count; i++) {
        int idx = i % a->length;
        vec->coeff[idx + offset] = a->coeff[idx] + 0.00001 * (idx % 7); // Slight perturbation with added computation
    }
}
