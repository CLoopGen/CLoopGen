#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint8_t *dst;
extern int zeros;
extern uint8_t *dst_end;
extern  uint8_t *src_end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t temp;
    int local_zeros = zeros;
    for (; src < src_end; src++, dst++) {
        temp = *src;
        if (local_zeros == 2) {
            int insert_ep3_byte = temp <= 3;
            if (insert_ep3_byte) {
                if (dst + 1 < dst_end) {
                    *(dst + 1) = 3;
                }
                dst++;
            }
        }
        if (dst < dst_end)
            *dst = temp;
        if (!temp)
            local_zeros++;
        else
            local_zeros = 0;
    }
    zeros = local_zeros;
}
