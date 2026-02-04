#include <stdio.h>

#include <inttypes.h>

struct poly_st {
    uint32_t coeff[256];
};


typedef struct poly_st POLY;

extern uint32_t omega;
extern int i;
extern int j;
extern int k;
extern size_t coeff_index;
extern POLY *p;
extern uint8_t *data;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided Memory Access Pattern
    // Instead of processing all coefficients in natural order, access them with a stride of 4,
    // unrolling the inner loop to process multiple indices per iteration for improved cache behavior.
    for (i = 0; i < k; i++, p++) {
        size_t base_index = coeff_index;
        // Process coefficients with stride 4, handling remainder separately
        for (j = 0; j < 64; j++) {
            int idx0 = j * 4 + 0;
            int idx1 = j * 4 + 1;
            int idx2 = j * 4 + 2;
            int idx3 = j * 4 + 3;

            if (p->coeff[idx0] != 0) data[coeff_index++] = idx0;
            if (p->coeff[idx1] != 0) data[coeff_index++] = idx1;
            if (p->coeff[idx2] != 0) data[coeff_index++] = idx2;
            if (p->coeff[idx3] != 0) data[coeff_index++] = idx3;
        }
        data[omega + i] = (uint8_t)coeff_index;
    }
}
