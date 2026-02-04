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
    for (i = 0; i < linesize; i++) {
        int32_t sum = 0;
        sum += (*in_lines_cur[0]++) * coef[0];
        sum += (*in_lines_cur[1]++) * coef[1];
        work_line[i] = sum;

        int32_t sum2 = 0;
        sum2 += (*in_lines_cur[2]++) * coef[2];
        sum2 += (*in_lines_cur[3]++) * coef[3];
        work_line[i] += sum2;
    }
}
