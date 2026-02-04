#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *work_line;
extern  int16_t *coef;
extern int linesize;
extern uint16_t *in_lines_cur[5];
extern uint16_t *in_lines_adj[5];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < linesize; i++) {
        int j = 0;
        *work_line += *in_lines_cur[j]++ * coef[j];
        *work_line += *in_lines_adj[j]++ * coef[j];
        j++;
        *work_line += *in_lines_cur[j]++ * coef[j];
        *work_line += *in_lines_adj[j]++ * coef[j];
        j++;
        *work_line += *in_lines_cur[j]++ * coef[j];
        *work_line += *in_lines_adj[j]++ * coef[j];
        j++;
        *work_line += *in_lines_cur[j]++ * coef[j];
        *work_line += *in_lines_adj[j]++ * coef[j];
        j++;
        *work_line += *in_lines_cur[j]++ * coef[j];
        *work_line++ += *in_lines_adj[j]++ * coef[j];
    }
}
