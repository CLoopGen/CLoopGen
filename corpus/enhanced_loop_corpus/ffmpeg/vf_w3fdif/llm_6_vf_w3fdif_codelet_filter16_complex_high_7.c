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
    int32_t temp_accum = *work_line; // Introduce temporary to modify data dependency (WAW and RAW removed on work_line)
    for (i = 0; i < linesize; i++) {
        temp_accum += *in_lines_cur[0]++ * coef[0];
        temp_accum += *in_lines_adj[0]++ * coef[0];
        temp_accum += *in_lines_cur[1]++ * coef[1];
        temp_accum += *in_lines_adj[1]++ * coef[1];
        temp_accum += *in_lines_cur[2]++ * coef[2];
        temp_accum += *in_lines_adj[2]++ * coef[2];
        temp_accum += *in_lines_cur[3]++ * coef[3];
        temp_accum += *in_lines_adj[3]++ * coef[3];
        temp_accum += *in_lines_cur[4]++ * coef[4];
        temp_accum += *in_lines_adj[4]++ * coef[4];
    }
    *work_line = temp_accum; // Single write at end, eliminating loop-carried WAW and RAW dependencies on work_line
}
