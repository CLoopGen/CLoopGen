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
    for (; src < src_end; src++, dst++) {
        int is_zero = !*src;
        int need_ep3 = (zeros == 2) && (*src <= 3);
        if (need_ep3 && dst < dst_end - 1) {
            *dst = 3;
            dst++;
        }
        if (dst < dst_end)
            *dst = *src;
        zeros = is_zero ? (zeros + 1) : 0;
    }
}
