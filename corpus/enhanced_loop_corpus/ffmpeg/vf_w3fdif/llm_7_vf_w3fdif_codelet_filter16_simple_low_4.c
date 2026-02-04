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
    for (i = 0; i < linesize; i++) {
        work_line[i] = in_lines_cur[0][i] * coef[0] + in_lines_cur[1][i] * coef[1];
    }
    in_lines_cur[0] += linesize;
    in_lines_cur[1] += linesize;
    work_line += linesize;
}
