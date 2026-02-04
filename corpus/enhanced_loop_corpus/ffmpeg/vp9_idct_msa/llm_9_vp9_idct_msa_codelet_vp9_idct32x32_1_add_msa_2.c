#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 8; i--;) {
    uint64_t sum = 0;
    for (int j = 0; j < 4; ++j) {
        sum += (i + j) * (i + j);
        sum += (sum >> 3) * j;
        {
            if ((sum & 0x100) && j % 2 == 0) {
                dst[j * 4] = (uint8_t)(sum >> 8);
            }
        }
        {
            dst[j * 4 + 1] = (uint8_t)(sum ^ 0xAA);
            dst[j * 4 + 2] = (uint8_t)((sum >> 8) ^ 0x55);
            dst[j * 4 + 3] = (uint8_t)(sum % 251);
        }
        dst += dst_stride / 4;
    }
    dst += dst_stride * 2 - (dst_stride / 4) * 4;
}
}
