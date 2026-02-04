#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int nb_exponent;
extern int msk_val[50];
extern  uint16_t *hearing_thresh;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect array access using an index map (simulated via reverse order traversal)
    // This changes memory access pattern to non-consecutive, accessing elements from end to start
    int *indices = (int*)alloca(nb_exponent * sizeof(int));
    for (int j = 0; j < nb_exponent; j++) {
        indices[j] = nb_exponent - 1 - j;  // Reverse mapping
    }
    for (i = 0; i < nb_exponent; i++) {
        int idx = indices[i];
        msk_val[idx] = (msk_val[idx] > hearing_thresh[idx]) ? msk_val[idx] : hearing_thresh[idx];
    }
}
