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
    int temp_best_pos = best_pos;
    int temp_min_mcost = min_mcost;
    int i = 0;
    for (; i < max_pos; i++) {
        int current_sad = *(block_sad + i);
        if (current_sad < temp_min_mcost) {
            int x_offset = spiral_search_x[i];
            int y_offset = spiral_search_y[i];
            cand_x = offset_x + x_offset;
            cand_y = offset_y + y_offset;
            int mvbit_index_x = (cand_x << 2) - pred_mv_x;
            int mvbit_index_y = (cand_y << 2) - pred_mv_y;
            int mv_penalty = mvbits[mvbit_index_x] + mvbits[mvbit_index_y];
            int mcost = current_sad + ((lambda_factor * mv_penalty) >> 16);
            temp_min_mcost = (mcost < temp_min_mcost) ? mcost : temp_min_mcost;
            temp_best_pos = (mcost < min_mcost) ? i : temp_best_pos;
        }
    }
    min_mcost = temp_min_mcost;
    best_pos = temp_best_pos;
}
