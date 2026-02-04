#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *work_line;
extern uint8_t *in_lines_cur[5];
extern uint8_t *in_lines_adj[5];
extern  int16_t *coef;
extern int linesize;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with manual pointer arithmetic unrolled in groups
    // Access pattern changed to process two elements at a time (semi-vectorized appearance), 
    // reducing loop iterations by half and using consecutive dereferences where possible.
    int limit = linesize / 2;
    for (i = 0; i < limit; i++) {
        *work_line += (*in_lines_cur[0]) * coef[0]; ++in_lines_cur[0];
        *work_line += (*in_lines_adj[0]) * coef[0]; ++in_lines_adj[0];
        *work_line += (*in_lines_cur[0]) * coef[0]; ++in_lines_cur[0];
        *work_line += (*in_lines_adj[0]) * coef[0]; ++in_lines_adj[0];

        *work_line += (*in_lines_cur[1]) * coef[1]; ++in_lines_cur[1];
        *work_line += (*in_lines_adj[1]) * coef[1]; ++in_lines_adj[1];
        *work_line += (*in_lines_cur[1]) * coef[1]; ++in_lines_cur[1];
        *work_line += (*in_lines_adj[1]) * coef[1]; ++in_lines_adj[1];

        *work_line += (*in_lines_cur[2]) * coef[2]; ++in_lines_cur[2];
        *work_line += (*in_lines_adj[2]) * coef[2]; ++in_lines_adj[2];
        *work_line += (*in_lines_cur[2]) * coef[2]; ++in_lines_cur[2];
        *work_line += (*in_lines_adj[2]) * coef[2]; ++in_lines_adj[2];

        *work_line += (*in_lines_cur[3]) * coef[3]; ++in_lines_cur[3];
        *work_line += (*in_lines_adj[3]) * coef[3]; ++in_lines_adj[3];
        *work_line += (*in_lines_cur[3]) * coef[3]; ++in_lines_cur[3];
        *work_line += (*in_lines_adj[3]) * coef[3]; ++in_lines_adj[3];

        *work_line += (*in_lines_cur[4]) * coef[4]; ++in_lines_cur[4];
        *work_line += (*in_lines_adj[4]) * coef[4]; ++in_lines_adj[4];
        *work_line += (*in_lines_cur[4]) * coef[4]; ++in_lines_cur[4];
        *work_line++ += (*in_lines_adj[4]) * coef[4]; ++in_lines_adj[4];
    }

    // Handle remaining iteration if linesize is odd
    if (linesize % 2) {
        i = limit * 2;
        for (; i < linesize; i++) {
            *work_line += *in_lines_cur[0]++ * coef[0];
            *work_line += *in_lines_adj[0]++ * coef[0];
            *work_line += *in_lines_cur[1]++ * coef[1];
            *work_line += *in_lines_adj[1]++ * coef[1];
            *work_line += *in_lines_cur[2]++ * coef[2];
            *work_line += *in_lines_adj[2]++ * coef[2];
            *work_line += *in_lines_cur[3]++ * coef[3];
            *work_line += *in_lines_adj[3]++ * coef[3];
            *work_line += *in_lines_cur[4]++ * coef[4];
            *work_line++ += *in_lines_adj[4]++ * coef[4];
        }
    }
}
