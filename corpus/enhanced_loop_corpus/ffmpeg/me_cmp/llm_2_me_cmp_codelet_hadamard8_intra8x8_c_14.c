#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern ptrdiff_t stride;
extern int i;
extern int temp[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i++) {
    int offset = stride * i;
    uint8_t *src_offset = &src[offset];
    int *temp_offset = &temp[8 * i];

    temp_offset[0] = src_offset[0] + src_offset[1];
    temp_offset[1] = src_offset[0] - src_offset[1];
    temp_offset[2] = src_offset[2] + src_offset[3];
    temp_offset[3] = src_offset[2] - src_offset[3];
    temp_offset[4] = src_offset[4] + src_offset[5];
    temp_offset[5] = src_offset[4] - src_offset[5];
    temp_offset[6] = src_offset[6] + src_offset[7];
    temp_offset[7] = src_offset[6] - src_offset[7];

    {
        int a = temp_offset[0], b = temp_offset[2];
        temp_offset[0] = a + b;
        temp_offset[2] = a - b;
    }
    {
        int a = temp_offset[1], b = temp_offset[3];
        temp_offset[1] = a + b;
        temp_offset[3] = a - b;
    }
    {
        int a = temp_offset[4], b = temp_offset[6];
        temp_offset[4] = a + b;
        temp_offset[6] = a - b;
    }
    {
        int a = temp_offset[5], b = temp_offset[7];
        temp_offset[5] = a + b;
        temp_offset[7] = a - b;
    }
    {
        int a = temp_offset[0], b = temp_offset[4];
        temp_offset[0] = a + b;
        temp_offset[4] = a - b;
    }
    {
        int a = temp_offset[1], b = temp_offset[5];
        temp_offset[1] = a + b;
        temp_offset[5] = a - b;
    }
    {
        int a = temp_offset[2], b = temp_offset[6];
        temp_offset[2] = a + b;
        temp_offset[6] = a - b;
    }
    {
        int a = temp_offset[3], b = temp_offset[7];
        temp_offset[3] = a + b;
        temp_offset[7] = a - b;
    }
}
}
