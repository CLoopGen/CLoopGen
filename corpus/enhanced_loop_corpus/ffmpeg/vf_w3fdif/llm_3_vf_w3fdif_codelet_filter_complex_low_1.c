#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *work_line;
extern uint8_t *in_lines_cur[4];
extern  int16_t *coef;
extern int linesize;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access – process every 2nd element in a blocked fashion
    // This changes access pattern to strided and processes half the elements per iteration
    int stride = 2;
    int n = linesize / stride;
    if (linesize % stride) n++;  // Handle remainder

    for (i = 0; i < n; i++) {
        int idx = i * stride;
        if (idx < linesize) {
            *work_line = in_lines_cur[0][idx] * coef[0];
            *work_line += in_lines_cur[1][idx] * coef[1];
            *work_line += in_lines_cur[2][idx] * coef[2];
            *work_line++ += in_lines_cur[3][idx] * coef[3];
        }
        idx++;
        if (idx < linesize) {
            *work_line = in_lines_cur[0][idx] * coef[0];
            *work_line += in_lines_cur[1][idx] * coef[1];
            *work_line += in_lines_cur[2][idx] * coef[2];
            *work_line++ += in_lines_cur[3][idx] * coef[3];
        }
    }
}
