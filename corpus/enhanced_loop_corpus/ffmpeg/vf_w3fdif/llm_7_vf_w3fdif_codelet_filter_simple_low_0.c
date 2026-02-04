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
    int32_t prev_result = 0;
    for (i = 0; i < linesize; i++) {
        *work_line = *in_lines_cur[0]++ * coef[0] + prev_result;
        prev_result = *in_lines_cur[1]++ * coef[1];
        work_line++;
    }
    *work_line = prev_result; // Store final dependency outside main computation flow
}
