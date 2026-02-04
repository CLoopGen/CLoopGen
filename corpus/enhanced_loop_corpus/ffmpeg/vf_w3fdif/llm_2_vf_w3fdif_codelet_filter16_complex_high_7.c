#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *work_line;
extern  int16_t *coef;
extern int linesize;
extern uint16_t *in_lines_cur[5];
extern uint16_t *in_lines_adj[5];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with manual loop unrolling and array indexing
    for (i = 0; i < linesize; i++) {
        int32_t sum = work_line[i];
        const uint16_t* cur_base = &in_lines_cur[0][i];
        const uint16_t* adj_base = &in_lines_adj[0][i];
        
        sum += cur_base[0 * linesize] * coef[0];
        sum += adj_base[0 * linesize] * coef[0];
        sum += cur_base[1 * linesize] * coef[1];
        sum += adj_base[1 * linesize] * coef[1];
        sum += cur_base[2 * linesize] * coef[2];
        sum += adj_base[2 * linesize] * coef[2];
        sum += cur_base[3 * linesize] * coef[3];
        sum += adj_base[3 * linesize] * coef[3];
        sum += cur_base[4 * linesize] * coef[4];
        sum += adj_base[4 * linesize] * coef[4];

        work_line[i] = sum;
    }
}
