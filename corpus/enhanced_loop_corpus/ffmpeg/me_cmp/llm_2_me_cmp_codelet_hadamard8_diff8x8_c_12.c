#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern ptrdiff_t stride;
extern int i;
extern int temp[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i++) {
    int row_offset = stride * i;
    uint8_t *src_row = &src[row_offset];
    uint8_t *dst_row = &dst[row_offset];
    int *temp_row = &temp[8 * i];

    temp_row[0] = (src_row[0] - dst_row[0]) + (src_row[1] - dst_row[1]);
    temp_row[1] = (src_row[0] - dst_row[0]) - (src_row[1] - dst_row[1]);
    temp_row[2] = (src_row[2] - dst_row[2]) + (src_row[3] - dst_row[3]);
    temp_row[3] = (src_row[2] - dst_row[2]) - (src_row[3] - dst_row[3]);
    temp_row[4] = (src_row[4] - dst_row[4]) + (src_row[5] - dst_row[5]);
    temp_row[5] = (src_row[4] - dst_row[4]) - (src_row[5] - dst_row[5]);
    temp_row[6] = (src_row[6] - dst_row[6]) + (src_row[7] - dst_row[7]);
    temp_row[7] = (src_row[6] - dst_row[6]) - (src_row[7] - dst_row[7]);

    {
        int a = temp_row[0], b = temp_row[2];
        temp_row[0] = a + b;
        temp_row[2] = a - b;
    }
    {
        int a = temp_row[1], b = temp_row[3];
        temp_row[1] = a + b;
        temp_row[3] = a - b;
    }
    {
        int a = temp_row[4], b = temp_row[6];
        temp_row[4] = a + b;
        temp_row[6] = a - b;
    }
    {
        int a = temp_row[5], b = temp_row[7];
        temp_row[5] = a + b;
        temp_row[7] = a - b;
    }
    {
        int a = temp_row[0], b = temp_row[4];
        temp_row[0] = a + b;
        temp_row[4] = a - b;
    }
    {
        int a = temp_row[1], b = temp_row[5];
        temp_row[1] = a + b;
        temp_row[5] = a - b;
    }
    {
        int a = temp_row[2], b = temp_row[6];
        temp_row[2] = a + b;
        temp_row[6] = a - b;
    }
    {
        int a = temp_row[3], b = temp_row[7];
        temp_row[3] = a + b;
        temp_row[7] = a - b;
    }
}
}
