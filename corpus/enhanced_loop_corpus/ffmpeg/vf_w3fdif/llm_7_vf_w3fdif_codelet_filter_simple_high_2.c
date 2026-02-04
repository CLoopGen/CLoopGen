#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *work_line;
extern uint8_t *in_lines_cur[3];
extern uint8_t *in_lines_adj[3];
extern  int16_t *coef;
extern int linesize;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < linesize; i++) {
        int32_t sum = 0;
        sum += *in_lines_cur[0]++ * coef[0];
        sum += *in_lines_adj[0]++ * coef[0];
        sum += *in_lines_cur[1]++ * coef[1];
        sum += *in_lines_adj[1]++ * coef[1];
        sum += *in_lines_cur[2]++ * coef[2];
        sum += *in_lines_adj[2]++ * coef[2];
        *work_line++ += sum;
    }
}
