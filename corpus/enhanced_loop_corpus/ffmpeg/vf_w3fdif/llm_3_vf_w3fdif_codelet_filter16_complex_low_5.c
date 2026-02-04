#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *work_line;
extern  int16_t *coef;
extern int linesize;
extern uint16_t *in_lines_cur[4];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access — access every 2nd element first, then odd indices (tiling-like pattern)
    int32_t *wl = work_line;
    int half_size = (linesize + 1) / 2;
    int i;

    // Process even indices first (stride-2 access)
    for (i = 0; i < half_size; i++) {
        int idx = i * 2;
        if (idx < linesize) {
            wl[idx] = in_lines_cur[0][idx] * coef[0];
            wl[idx] += in_lines_cur[1][idx] * coef[1];
            wl[idx] += in_lines_cur[2][idx] * coef[2];
            wl[idx] += in_lines_cur[3][idx] * coef[3];
        }
    }

    // Then process odd indices (second stride-2 pass)
    for (i = 0; i < half_size; i++) {
        int idx = i * 2 + 1;
        if (idx < linesize) {
            wl[idx] = in_lines_cur[0][idx] * coef[0];
            wl[idx] += in_lines_cur[1][idx] * coef[1];
            wl[idx] += in_lines_cur[2][idx] * coef[2];
            wl[idx] += in_lines_cur[3][idx] * coef[3];
        }
    }

    // Update global work_line to end of processed data
    work_line += linesize;
}
