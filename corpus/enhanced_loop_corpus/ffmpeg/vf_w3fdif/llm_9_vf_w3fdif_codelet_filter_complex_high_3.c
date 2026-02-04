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
    for (i = 0; i < linesize; i++) {
        int32_t temp = 0;
        temp += (*in_lines_cur[0]++) * coef[0];
        temp += (*in_lines_adj[0]++) * coef[0];
        temp += (*in_lines_cur[1]++) * coef[1];
        temp += (*in_lines_adj[1]++) * coef[1];
        temp += (*in_lines_cur[2]++) * coef[2];
        temp += (*in_lines_adj[2]++) * coef[2];

        *work_line += temp;

        int32_t temp2 = 0;
        temp2 += (*in_lines_cur[3]++) * coef[3];
        temp2 += (*in_lines_adj[3]++) * coef[3];
        temp2 += (*in_lines_cur[4]++) * coef[4];
        temp2 += (*in_lines_adj[4]++) * coef[4];

        *work_line++ += temp2;
    }
}
