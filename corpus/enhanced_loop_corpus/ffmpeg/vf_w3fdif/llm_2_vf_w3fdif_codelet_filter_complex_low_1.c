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
    // Variant 1: Consecutive memory access with array indexing (eliminates pointer arithmetic)
    for (i = 0; i < linesize; i++) {
        int32_t sum = in_lines_cur[0][i] * coef[0];
        sum += in_lines_cur[1][i] * coef[1];
        sum += in_lines_cur[2][i] * coef[2];
        sum += in_lines_cur[3][i] * coef[3];
        work_line[i] = sum;
    }
}
