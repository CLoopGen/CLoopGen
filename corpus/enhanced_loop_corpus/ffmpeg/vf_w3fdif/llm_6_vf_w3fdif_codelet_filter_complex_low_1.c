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
    int32_t temp[4];
    for (i = 0; i < linesize; i++) {
        temp[0] = *in_lines_cur[0]++ * coef[0];
        temp[1] = *in_lines_cur[1]++ * coef[1];
        temp[2] = *in_lines_cur[2]++ * coef[2];
        temp[3] = *in_lines_cur[3]++ * coef[3];
        *work_line++ = temp[0] + temp[1] + temp[2] + temp[3];
    }
}
