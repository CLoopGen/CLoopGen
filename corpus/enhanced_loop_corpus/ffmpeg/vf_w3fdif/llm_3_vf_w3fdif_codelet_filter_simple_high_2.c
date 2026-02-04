#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *work_line;
extern uint8_t *in_lines_cur[3];
extern uint8_t *in_lines_adj[3];
extern  int16_t *coef;
extern int linesize;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with indirect indexing using a step pattern
    // Simulate strided access by stepping every 2 elements and processing two lanes
    int stride = 2;
    int n = linesize / stride;  // Number of full strides
    for (i = 0; i < n; i++) {
        int idx = i * stride;
        *work_line += in_lines_cur[0][idx] * coef[0];
        *work_line += in_lines_adj[0][idx] * coef[0];
        *work_line += in_lines_cur[1][idx] * coef[1];
        *work_line += in_lines_adj[1][idx] * coef[1];
        *work_line += in_lines_cur[2][idx] * coef[2];
        *work_line++ += in_lines_adj[2][idx] * coef[2];
    }
    // Handle remaining elements if linesize is not divisible by stride
    for (; i * stride < linesize; i++) {
        int idx = i * stride;
        *work_line += in_lines_cur[0][idx] * coef[0];
        *work_line += in_lines_adj[0][idx] * coef[0];
        *work_line += in_lines_cur[1][idx] * coef[1];
        *work_line += in_lines_adj[1][idx] * coef[1];
        *work_line += in_lines_cur[2][idx] * coef[2];
        *work_line++ += in_lines_adj[2][idx] * coef[2];
    }
}
