#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *work_line;
extern  int16_t *coef;
extern int linesize;
extern uint16_t *in_lines_cur[4];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic unrolled by 2
    int32_t *wl = work_line;
    uint16_t **in_cur = in_lines_cur;
    int16_t *c = coef;
    int i;

    for (i = 0; i < linesize; i += 2) {
        // Unroll factor 2: process two iterations at once with consecutive access
        int32_t sum0 = in_cur[0][0] * c[0] + in_cur[1][0] * c[1] +
                       in_cur[2][0] * c[2] + in_cur[3][0] * c[3];
        int32_t sum1 = 0;

        wl[0] = sum0;

        if (i + 1 < linesize) {
            sum1 = in_cur[0][1] * c[0] + in_cur[1][1] * c[1] +
                   in_cur[2][1] * c[2] + in_cur[3][1] * c[3];
            wl[1] = sum1;

            // Advance all pointers by 2
            in_cur[0] += 2;
            in_cur[1] += 2;
            in_cur[2] += 2;
            in_cur[3] += 2;
            wl += 2;
        } else {
            // Advance by 1 for partial unroll
            in_cur[0]++;
            in_cur[1]++;
            in_cur[2]++;
            in_cur[3]++;
            wl++;
        }
    }

    // Update global pointers and work_line to reflect final position
    work_line = wl;
}
