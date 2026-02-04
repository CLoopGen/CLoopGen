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
    for (; src < src_end && dst < dst_end; src++, dst++) {
        if (zeros == 2) {
            int insert_ep3_byte = *src <= 3;
            if (insert_ep3_byte) {
                if (dst + 1 < dst_end) {
                    dst++;
                    *dst = 3;
                }
            }
        }
        *dst = *src;
        if (!*src)
            zeros++;
        else
            zeros = 0;
    }
}
