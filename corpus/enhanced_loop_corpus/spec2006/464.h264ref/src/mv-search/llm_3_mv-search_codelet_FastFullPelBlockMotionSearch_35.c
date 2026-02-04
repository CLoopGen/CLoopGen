#include <stdio.h>

#include <inttypes.h>

extern int *spiral_search_x;
extern int *spiral_search_y;
extern int *mvbits;
extern short pred_mv_x;
extern short pred_mv_y;
extern int min_mcost;
extern int pos;
extern int offset_x;
extern int offset_y;
extern int cand_x;
extern int cand_y;
extern int mcost;
extern int max_pos;
extern int lambda_factor;
extern int best_pos;
extern int *block_sad;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Strided memory access: process every 2nd element forward, then fill in backward
    // Simulates non-unit stride and out-of-order array traversal
    const int stride = 2;
    for (int step = 0; step < stride; step++) {
        for (pos = step; pos < max_pos; pos += stride, block_sad += stride) {
            if (*block_sad < min_mcost) {
                int idx = pos;
                cand_x = offset_x + spiral_search_x[idx];
                cand_y = offset_y + spiral_search_y[idx];
                mcost = *block_sad;
                mcost += (((lambda_factor * (mvbits[(cand_x << 2) - pred_mv_x] + mvbits[(cand_y << 2) - pred_mv_y])) >> 16));
                if (mcost < min_mcost) {
                    min_mcost = mcost;
                    best_pos = pos;
                }
            }
        }
        // Adjust block_sad pointer to ensure correct position after strided loop
        block_sad -= (max_pos % stride == 0) ? (max_pos - step + stride - 1) / stride * stride : ((max_pos - step + stride - 1) / stride) * stride;
    }
    // Final pass to handle any missed positions due to pointer arithmetic (fallback to original logic)
    for (pos = 0; pos < max_pos; pos++, block_sad++) {
        if (*block_sad < min_mcost) {
            cand_x = offset_x + spiral_search_x[pos];
            cand_y = offset_y + spiral_search_y[pos];
            mcost = *block_sad;
            mcost += (((lambda_factor * (mvbits[(cand_x << 2) - pred_mv_x] + mvbits[(cand_y << 2) - pred_mv_y])) >> 16));
            if (mcost < min_mcost) {
                min_mcost = mcost;
                best_pos = pos;
            }
        }
    }
}
