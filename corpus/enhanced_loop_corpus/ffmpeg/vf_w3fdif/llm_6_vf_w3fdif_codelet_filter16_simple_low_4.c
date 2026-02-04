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
    int32_t temp1, temp2;
    for (i = 0; i < linesize; i++) {
        temp1 = *in_lines_cur[0]++ * coef[0];
        temp2 = *in_lines_cur[1]++ * coef[1];
        *work_line++ = temp1 + temp2;
    }
}
