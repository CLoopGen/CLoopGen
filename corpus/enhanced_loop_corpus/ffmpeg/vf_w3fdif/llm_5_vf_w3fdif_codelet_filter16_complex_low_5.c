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
        if (*in_lines_cur[0] > 0) {
            sum += *in_lines_cur[0]++ * coef[0];
        } else {
            in_lines_cur[0]++;
            sum += coef[0]; 
        }
        if (i % 2 == 0) {
            sum += *in_lines_cur[1]++ * coef[1];
        } else {
            in_lines_cur[1]++;
        }
        sum += *in_lines_cur[2]++ * coef[2];
        sum += *in_lines_cur[3]++ * coef[3];
        *work_line++ = sum;
    }
}
