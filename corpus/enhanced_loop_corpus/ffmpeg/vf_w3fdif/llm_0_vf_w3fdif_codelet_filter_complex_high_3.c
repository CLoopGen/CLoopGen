#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *work_line;
extern uint8_t *in_lines_cur[5];
extern uint8_t *in_lines_adj[5];
extern  int16_t *coef;
extern int linesize;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < linesize; i += 2) {
        int32_t temp1 = 0, temp2 = 0;
        temp1 += *in_lines_cur[0]++ * coef[0];
        temp1 += *in_lines_adj[0]++ * coef[0];
        temp1 += *in_lines_cur[1]++ * coef[1];
        temp1 += *in_lines_adj[1]++ * coef[1];
        temp1 += *in_lines_cur[2]++ * coef[2];
        temp1 += *in_lines_adj[2]++ * coef[2];
        temp1 += *in_lines_cur[3]++ * coef[3];
        temp1 += *in_lines_adj[3]++ * coef[3];
        temp1 += *in_lines_cur[4]++ * coef[4];

        if (i + 1 < linesize) {
            temp2 += *in_lines_cur[0]++ * coef[0];
            temp2 += *in_lines_adj[0]++ * coef[0];
            temp2 += *in_lines_cur[1]++ * coef[1];
            temp2 += *in_lines_adj[1]++ * coef[1];
            temp2 += *in_lines_cur[2]++ * coef[2];
            temp2 += *in_lines_adj[2]++ * coef[2];
            temp2 += *in_lines_cur[3]++ * coef[3];
            temp2 += *in_lines_adj[3]++ * coef[3];
            temp2 += *in_lines_cur[4]++ * coef[4];
        }

        *work_line++ += temp1;
        if (i + 1 < linesize) {
            *work_line++ += temp2;
        }
    }
}
