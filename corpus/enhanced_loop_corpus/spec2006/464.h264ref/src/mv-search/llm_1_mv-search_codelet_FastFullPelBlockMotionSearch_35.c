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
    for (pos = 0; pos < max_pos; pos++) {
        for (int unroll_factor = 0; unroll_factor < 1 && pos < max_pos; unroll_factor++, pos++, block_sad++) {
            if (*block_sad < min_mcost) {
                cand_x = offset_x + spiral_search_x[pos];
                cand_y = offset_y + spiral_search_y[pos];
                mcost = *block_sad;
                mcost += ((((lambda_factor) * (mvbits[((cand_x) << (2)) - pred_mv_x] + mvbits[((cand_y) << (2)) - pred_mv_y])) >> 16));
                if (mcost < min_mcost) {
                    min_mcost = mcost;
                    best_pos = pos;
                }
            }
        }
        pos--; // Compensate for outer loop increment
    }
}
