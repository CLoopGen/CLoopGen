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
    int local_min_mcost = min_mcost;
    for (pos = 0; pos < max_pos; pos++, block_sad++) {
        if (*block_sad < local_min_mcost) {
            cand_x = offset_x + spiral_search_x[pos];
            cand_y = offset_y + spiral_search_y[pos];
            int local_mcost = *block_sad;
            local_mcost += (((lambda_factor * (mvbits[(cand_x << 2) - pred_mv_x] + mvbits[(cand_y << 2) - pred_mv_y])) >> 16));
            if (local_mcost < local_min_mcost) {
                local_min_mcost = local_mcost;
                best_pos = pos;
            }
        }
    }
    min_mcost = local_min_mcost;
}
