#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *work_line;
extern  int16_t *coef;
extern int linesize;
extern uint16_t *in_lines_cur[3];
extern uint16_t *in_lines_adj[3];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = 0; outer < linesize; outer += 2) {
        for (int inner = 0; inner < 2 && (outer + inner) < linesize; inner++) {
            i = outer + inner;
            *work_line += *in_lines_cur[0]++ * coef[0];
            *work_line += *in_lines_adj[0]++ * coef[0];
            *work_line += *in_lines_cur[1]++ * coef[1];
            *work_line += *in_lines_adj[1]++ * coef[1];
            *work_line += *in_lines_cur[2]++ * coef[2];
            *work_line++ += *in_lines_adj[2]++ * coef[2];
        }
    }
}
