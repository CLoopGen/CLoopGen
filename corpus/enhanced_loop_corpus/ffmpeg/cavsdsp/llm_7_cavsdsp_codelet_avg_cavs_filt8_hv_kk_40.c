#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src1;
extern ptrdiff_t srcStride;
extern int16_t *tmp;
extern  int h;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int16_t prev_tmp7 = 0;
for (i = 0; i < h + 5; i++) {
    tmp[0] = prev_tmp7 + (-7 * src1[-1] + 42 * src1[0] + 96 * src1[1] - 2 * src1[2] - src1[3]);
    tmp[1] = tmp[0] + (-7 * src1[0] + 42 * src1[1] + 96 * src1[2] - 2 * src1[3] - src1[4]);
    tmp[2] = tmp[1] + (-7 * src1[1] + 42 * src1[2] + 96 * src1[3] - 2 * src1[4] - src1[5]);
    tmp[3] = tmp[2] + (-7 * src1[2] + 42 * src1[3] + 96 * src1[4] - 2 * src1[5] - src1[6]);
    tmp[4] = tmp[3] + (-7 * src1[3] + 42 * src1[4] + 96 * src1[5] - 2 * src1[6] - src1[7]);
    tmp[5] = tmp[4] + (-7 * src1[4] + 42 * src1[5] + 96 * src1[6] - 2 * src1[7] - src1[8]);
    tmp[6] = tmp[5] + (-7 * src1[5] + 42 * src1[6] + 96 * src1[7] - 2 * src1[8] - src1[9]);
    tmp[7] = tmp[6] + (-7 * src1[6] + 42 * src1[7] + 96 * src1[8] - 2 * src1[9] - src1[10]);

    prev_tmp7 = tmp[7];
    tmp += 8;
    src1 += srcStride;
}
}
