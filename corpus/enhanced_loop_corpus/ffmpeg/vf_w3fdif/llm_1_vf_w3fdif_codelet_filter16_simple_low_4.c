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
    for (i = 0; i < linesize; i += 2) {
        for (int k = 0; k < 2 && (i + k) < linesize; k++) {
            int idx = i + k;
            *work_line = *in_lines_cur[0]++ * coef[0];
            *work_line++ += *in_lines_cur[1]++ * coef[1];
        }
    }
}
