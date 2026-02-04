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
        for (int j = 0; j < 3; j++) {
            *work_line += *in_lines_cur[j]++ * coef[j];
            *work_line += *in_lines_adj[j]++ * coef[j];
            if (j == 2) {
                work_line++;
            }
        }
    }
}
