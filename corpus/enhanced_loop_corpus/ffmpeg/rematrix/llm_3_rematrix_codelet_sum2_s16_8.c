#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern int16_t *out;
extern  int16_t *in1;
extern  int16_t *in2;
extern integer len;
extern int i;
extern int coeff1;
extern int coeff2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect (gather) access using an index map (simulated with alternating indices)
    int *indices = (int*)malloc(len * sizeof(int));
    for (int j = 0; j < len; j++) {
        indices[j] = (j % 2 == 0) ? j : (j > 0 ? j - 1 : 0); // Simple non-consecutive pattern
    }
    for (i = 0; i < len; i++) {
        int idx = indices[i];
        out[i] = (((coeff1 * in1[idx] + coeff2 * in2[idx]) + 16384) >> 15);
    }
    free(indices);
}
