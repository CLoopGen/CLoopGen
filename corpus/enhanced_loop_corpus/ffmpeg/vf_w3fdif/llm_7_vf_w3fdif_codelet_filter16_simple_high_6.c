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
    // Reorder operations and introduce artificial loop-carried dependency via work_line propagation
    for (i = 0; i < linesize; i++) {
        int32_t current = *work_line; // Create RAW dependency: read before write
        current += *in_lines_cur[0]++ * coef[0];
        current += *in_lines_adj[0]++ * coef[0];
        *work_line = current;

        current += *in_lines_cur[1]++ * coef[1]; // Use previous result (WAW and RAW)
        current += *in_lines_adj[1]++ * coef[1];
        *work_line = current;

        current += *in_lines_cur[2]++ * coef[2]; // Accumulate in a serialized way
        *work_line = current + (*in_lines_adj[2]++ * coef[2]);
        work_line++; // Advance work_line only once per iteration
    }
}
