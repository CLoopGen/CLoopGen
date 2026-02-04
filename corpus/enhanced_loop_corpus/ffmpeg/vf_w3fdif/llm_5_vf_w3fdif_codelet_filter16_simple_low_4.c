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
        int32_t temp = 0;
        int16_t c0 = coef[0], c1 = coef[1];
        uint16_t in0 = *in_lines_cur[0], in1 = *in_lines_cur[1];

        if (c0) temp += in0 * c0;
        if (c1) temp += in1 * c1;

        *work_line = temp;
        work_line++;
        in_lines_cur[0]++;
        in_lines_cur[1]++;
    }
}
