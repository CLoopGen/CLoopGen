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
    // Variant 2: Strided memory access – process every 2nd element in a strided pattern
    // Simulates non-unit stride access for cache behavior analysis
    int stride = 2;
    int n = linesize / stride;
    for (i = 0; i < n; i++) {
        int idx = i * stride;
        *work_line += in_lines_cur[0][idx] * coef[0];
        *work_line += in_lines_adj[0][idx] * coef[0];
        *work_line += in_lines_cur[1][idx] * coef[1];
        *work_line += in_lines_adj[1][idx] * coef[1];
        *work_line += in_lines_cur[2][idx] * coef[2];
        *work_line++ += in_lines_adj[2][idx] * coef[2];
    }
    // Handle remainder if linesize is not divisible by stride
    for (; i * stride < linesize; i++) {
        *work_line += *in_lines_cur[0]++ * coef[0];
        *work_line += *in_lines_adj[0]++ * coef[0];
        *work_line += *in_lines_cur[1]++ * coef[1];
        *work_line += *in_lines_adj[1]++ * coef[1];
        *work_line += *in_lines_cur[2]++ * coef[2];
        *work_line++ += *in_lines_adj[2]++ * coef[2];
    }
}
