#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *work_line;
extern  int16_t *coef;
extern int linesize;
extern uint16_t *in_lines_cur[2];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (i = 0; i < linesize; i++) {
        int32_t val0 = in_lines_cur[0][i * 2] * coef[0];
        int32_t val1 = in_lines_cur[1][i * 2] * coef[1];
        work_line[i] = val0 + val1;
    }
}
