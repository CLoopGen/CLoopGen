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
        if (coef[0] == 0) {
            *work_line = 0;
        } else {
            *work_line = *in_lines_cur[0]++ * coef[0];
        }
        if (coef[1] != 0) {
            *work_line++ += *in_lines_cur[1]++ * coef[1];
        } else {
            *work_line++;
            in_lines_cur[1]++;
        }
    }
}
