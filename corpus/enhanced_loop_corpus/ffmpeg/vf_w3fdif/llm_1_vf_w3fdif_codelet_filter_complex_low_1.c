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
    for (int stride = 0; stride < linesize; stride += 4) {
        for (int step = 0; step < 4 && (stride + step) < linesize; step++) {
            *work_line = *in_lines_cur[0]++ * coef[0];
            *work_line += *in_lines_cur[1]++ * coef[1];
            *work_line += *in_lines_cur[2]++ * coef[2];
            *work_line++ += *in_lines_cur[3]++ * coef[3];
        }
    }
}
