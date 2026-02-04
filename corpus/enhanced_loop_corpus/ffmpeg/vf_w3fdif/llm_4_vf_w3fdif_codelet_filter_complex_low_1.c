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
    for (i = 0; i < linesize; i++) {
        if (coef[0] == 0) {
            *work_line = 0;
        } else {
            *work_line = *in_lines_cur[0]++ * coef[0];
        }
        if (coef[1] != 0) {
            *work_line += *in_lines_cur[1]++ * coef[1];
        }
        if (coef[2] != 0) {
            *work_line += *in_lines_cur[2]++ * coef[2];
        }
        if (coef[3] != 0) {
            *work_line++ += *in_lines_cur[3]++ * coef[3];
        } else {
            (*work_line)++;
            in_lines_cur[3]++;
        }
    }
}
