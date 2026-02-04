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
    // Variant 2: Strided access using pointer arithmetic with fixed stride and pre-computed offsets
    ptrdiff_t stride = 1; // Simulate non-unit stride if needed; here kept as 1 for correctness
    for (i = 0; i < linesize; i += stride) {
        // Access elements with artificial stride pattern (could be extended to >1)
        *work_line += in_lines_cur[0][i] * coef[0];
        *work_line += in_lines_adj[0][i] * coef[0];
        *work_line += in_lines_cur[1][i] * coef[1];
        *work_line += in_lines_adj[1][i] * coef[1];
        *work_line += in_lines_cur[2][i] * coef[2];
        *work_line += in_lines_adj[2][i] * coef[2];
        *work_line += in_lines_cur[3][i] * coef[3];
        *work_line += in_lines_adj[3][i] * coef[3];
        *work_line += in_lines_cur[4][i] * coef[4];
        *work_line++ += in_lines_adj[4][i] * coef[4];
    }
}
