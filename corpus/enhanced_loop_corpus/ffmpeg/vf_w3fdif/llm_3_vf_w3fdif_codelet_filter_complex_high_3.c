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
    // Variant 2: Strided memory access via index-based addressing with fixed stride of 2
    // Simulates processing every second pixel or sample, altering data reuse and access pattern.
    // This changes temporal and spatial locality, useful in downscaling or decimation scenarios.

    int stride = 2;
    int effective_size = (linesize + stride - 1) / stride;

    for (i = 0; i < effective_size; i++) {
        int idx = i * stride;

        // Use indexed access instead of pointer increment to allow striding
        *work_line += in_lines_cur[0][idx] * coef[0];
        if (idx + 1 < linesize) {
            *work_line += in_lines_adj[0][idx] * coef[0];
        }

        *work_line += in_lines_cur[1][idx] * coef[1];
        if (idx + 1 < linesize) {
            *work_line += in_lines_adj[1][idx] * coef[1];
        }

        *work_line += in_lines_cur[2][idx] * coef[2];
        if (idx + 1 < linesize) {
            *work_line += in_lines_adj[2][idx] * coef[2];
        }

        *work_line += in_lines_cur[3][idx] * coef[3];
        if (idx + 1 < linesize) {
            *work_line += in_lines_adj[3][idx] * coef[3];
        }

        *work_line += in_lines_cur[4][idx] * coef[4];
        if (idx + 1 < linesize) {
            *work_line++ += in_lines_adj[4][idx] * coef[4];
        }
    }

    // Update original pointers only if needed — here we assume side effects on global state are not required beyond computation.
    // If pointer advancement must reflect actual traversal, add:
    // for (int j = 0; j < 5; j++) {
    //     in_lines_cur[j] += effective_size * stride;
    //     in_lines_adj[j] += effective_size * stride;
    // }
}
