#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *work_line;
extern  int16_t *coef;
extern int linesize;
extern uint16_t *in_lines_cur[3];
extern uint16_t *in_lines_adj[3];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32_t temp_accum[3] = {0}; // Introduce temporary accumulators to modify data dependencies
    for (i = 0; i < linesize; i++) {
        temp_accum[0] += *in_lines_cur[0]++ * coef[0];
        temp_accum[0] += *in_lines_adj[0]++ * coef[0];
        temp_accum[1] += *in_lines_cur[1]++ * coef[1];
        temp_accum[1] += *in_lines_adj[1]++ * coef[1];
        temp_accum[2] += *in_lines_cur[2]++ * coef[2];
        temp_accum[2] += *in_lines_adj[2]++ * coef[2];
    }
    // Break loop-carried dependency on *work_line by accumulating locally, then store once
    *work_line += temp_accum[0] + temp_accum[1] + temp_accum[2];
}
