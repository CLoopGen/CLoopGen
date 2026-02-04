#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *work_line;
extern uint8_t *in_lines_cur[2];
extern  int16_t *coef;
extern int linesize;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < linesize; i++) {
        int32_t val0 = *in_lines_cur[0]++;
        int32_t val1 = *in_lines_cur[1]++;
        *work_line = val0 * coef[0] + val1 * coef[1];
        work_line++;
    }
}
