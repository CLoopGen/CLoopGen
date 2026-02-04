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
        int skip_first = (i % 2 == 0);
        int skip_last = (i % 3 == 0);

        if (!skip_first) {
            *work_line = *in_lines_cur[0]++ * coef[0];
            *work_line += *in_lines_cur[1]++ * coef[1];
        } else {
            *work_line = 0;
            in_lines_cur[0]++;
            in_lines_cur[1]++;
        }

        *work_line += *in_lines_cur[2]++ * coef[2];

        if (!skip_last) {
            *work_line++ += *in_lines_cur[3]++ * coef[3];
        } else {
            (*work_line)++;
            in_lines_cur[3]++;
        }
    }
}
