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
    // Introduce loop-carried dependency via pointer arithmetic and staggered accumulation
    // Simulate a sliding accumulation where each iteration depends on previous partial result
    int32_t prev = 0;
    for (i = 0; i < linesize; i++) {
        int32_t current = prev; // RAW dependency: current depends on prev from prior iteration

        current += *in_lines_cur[0]++ * coef[0];
        current += *in_lines_adj[0]++ * coef[0];
        current += *in_lines_cur[1]++ * coef[1];
        current += *in_lines_adj[1]++ * coef[1];
        current += *in_lines_cur[2]++ * coef[2];
        current += *in_lines_adj[2]++ * coef[2];
        current += *in_lines_cur[3]++ * coef[3];
        current += *in_lines_adj[3]++ * coef[3];
        current += *in_lines_cur[4]++ * coef[4];
        current += *in_lines_adj[4]++ * coef[4];

        *work_line++ = current; // Write once per iteration, advancing work_line
        prev = current; // Create loop-carried dependency (RAW) for next iteration
    }
}
