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
    int offset = 0;
    for (i = 0; i < linesize; i++) {
        work_line[offset] = in_lines_cur[0][i] * coef[0];
        work_line[offset] += in_lines_cur[1][i] * coef[1];
        work_line[offset] += in_lines_cur[2][i] * coef[2];
        work_line[offset] += in_lines_cur[3][i] * coef[3];
        offset++;
    }
}
