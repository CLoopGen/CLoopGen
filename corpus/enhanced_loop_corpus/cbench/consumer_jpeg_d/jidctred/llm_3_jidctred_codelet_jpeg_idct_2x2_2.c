#include <stdio.h>

#include <inttypes.h>

typedef long INT32;

typedef short JCOEF;

typedef JCOEF *JCOEFPTR;

typedef int ISLOW_MULT_TYPE;

extern INT32 tmp0;
extern INT32 tmp10;
extern INT32 z1;
extern JCOEFPTR inptr;
extern ISLOW_MULT_TYPE *quantptr;
extern int *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect Access via Index Mapping Array
    // Use a lookup table for non-uniform access patterns to simulate irregular strides.
    // This models scenarios where memory access depends on runtime-defined sparsity or transform rules.

    static const int index_map[8] = {0, 8, 16, 24, 32, 40, 48, 56}; // Original strided indices
    static const int ac_mask_idx[4] = {1, 3, 5, 7}; // AC coefficient offsets in index_map units

    for (ctr = 8; ctr > 0; ctr--) {
        int base_idx = 8 - ctr; // Logical block index
        int mapped_base = index_map[base_idx];

        if (ctr == 6 || ctr == 4 || ctr == 2)
            continue;

        // Check AC components using indirect indexing
        if ((inptr[mapped_base + index_map[ac_mask_idx[0]/8]] |
             inptr[mapped_base + index_map[ac_mask_idx[1]/8]] |
             inptr[mapped_base + index_map[ac_mask_idx[2]/8]] |
             inptr[mapped_base + index_map[ac_mask_idx[3]/8]]) == 0) {

            int dcval = (((ISLOW_MULT_TYPE)(inptr[mapped_base])) * (quantptr[mapped_base])) << 2;
            wsptr[mapped_base] = dcval;
            wsptr[mapped_base + 8] = dcval; // Output also uses indirect pattern
            continue;
        }

        z1 = (((ISLOW_MULT_TYPE)(inptr[mapped_base])) * (quantptr[mapped_base]));
        tmp10 = z1 << (13 + 2);

        z1 = (((ISLOW_MULT_TYPE)(inptr[mapped_base + index_map[7]])) * (quantptr[mapped_base + index_map[7]]));
        tmp0 = ((z1) * (-((INT32)5906)));

        z1 = (((ISLOW_MULT_TYPE)(inptr[mapped_base + index_map[5]])) * (quantptr[mapped_base + index_map[5]]));
        tmp0 += ((z1) * (((INT32)6967)));

        z1 = (((ISLOW_MULT_TYPE)(inptr[mapped_base + index_map[3]])) * (quantptr[mapped_base + index_map[3]]));
        tmp0 += ((z1) * (-((INT32)10426)));

        z1 = (((ISLOW_MULT_TYPE)(inptr[mapped_base + index_map[1]])) * (quantptr[mapped_base + index_map[1]]));
        tmp0 += ((z1) * (((INT32)29692)));

        int shift = 13 - 2 + 2;
        wsptr[mapped_base]      = (int)(((tmp10 + tmp0) + (((INT32)1) << (shift - 1))) >> shift);
        wsptr[mapped_base + 8]  = (int)(((tmp10 - tmp0) + (((INT32)1) << (shift - 1))) >> shift);
    }
}
