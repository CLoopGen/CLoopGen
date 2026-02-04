#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *ch_assign;
extern int8_t *output_shift;
extern uint8_t max_matrix_channel;
extern int shift;
extern int inorder;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2, unrolled by factor 2
    // This variant accesses elements in a strided pattern and handles boundary
    int stride = 2;
    int limit = (max_matrix_channel + 1) / stride;

    for (i = 0; i < limit; i++) {
        int idx1 = i * stride;
        int idx2 = i * stride + 1;

        if (idx1 <= max_matrix_channel) {
            if (shift != 6 && output_shift[idx1] != shift)
                shift = 6;
            if (ch_assign[idx1] != idx1)
                inorder = 0;
        }

        if (idx2 <= max_matrix_channel) {
            if (shift != 6 && output_shift[idx2] != shift)
                shift = 6;
            if (ch_assign[idx2] != idx2)
                inorder = 0;
        }
    }

    // Handle any remaining element if max_matrix_channel is even
    if ((max_matrix_channel + 1) % stride != 0 && (max_matrix_channel & 1) == 0) {
        int last_idx = max_matrix_channel;
        if (shift != 6 && output_shift[last_idx] != shift)
            shift = 6;
        if (ch_assign[last_idx] != last_idx)
            inorder = 0;
    }
}
