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
    // Split accumulation to create partial sums and alter dependency chains
    int32_t sum1 = 0, sum2 = 0;
    for (i = 0; i < linesize; i++) {
        sum1 += *in_lines_cur[0]++ * coef[0] + *in_lines_adj[0]++ * coef[0]
                  + *in_lines_cur[2]++ * coef[2] + *in_lines_adj[2]++ * coef[2]
                  + *in_lines_cur[4]++ * coef[4];
        sum2 += *in_lines_cur[1]++ * coef[1] + *in_lines_adj[1]++ * coef[1]
                  + *in_lines_cur[3]++ * coef[3] + *in_lines_adj[3]++ * coef[3]
                  + *in_lines_adj[4]++ * coef[4];
    }
    *work_line += sum1 + sum2; // Eliminate per-iteration memory update, reduce loop-carried dependency
}
