#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct FilterParams {
    uint8_t order;
    uint8_t shift;
    int32_t state[8];
    int coeff_bits;
    int coeff_shift;
} FilterParams;

extern FilterParams *fp;
extern int32_t *fcoeff;
extern int min;
extern int max;
extern int coeff_mask;
extern int order;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index map (simulated via reversed order traversal)
    // This changes access pattern from sequential to reverse sequential (a form of indirect access pattern)
    int i;
    for (i = fp->order - 1; i >= 0; i--) {
        int idx = i; // Reverse index used directly
        int coeff = fcoeff[idx];
        if (coeff < min)
            min = coeff;
        if (coeff > max)
            max = coeff;
        coeff_mask |= coeff;
    }
}
