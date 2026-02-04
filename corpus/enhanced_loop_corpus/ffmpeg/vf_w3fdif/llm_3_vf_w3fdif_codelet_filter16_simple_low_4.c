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
    // Variant 2: Consecutive array access using pointer arithmetic with pre-increment and local accumulation
    int16_t *ptr0 = in_lines_cur[0];
    int16_t *ptr1 = in_lines_cur[1];
    int32_t *wline = work_line;
    int32_t temp_coef0 = coef[0];
    int32_t temp_coef1 = coef[1];

    for (i = 0; i < linesize; i++) {
        *wline++ = (*ptr0++ * temp_coef0) + (*ptr1++ * temp_coef1);
    }

    // Update the global pointers to reflect advancement
    in_lines_cur[0] = ptr0;
    in_lines_cur[1] = ptr1;
    work_line = wline;
}
