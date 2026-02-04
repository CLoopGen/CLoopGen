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
for (; src < src_end; src++ , dst++) {
    if (zeros == 2) {
        int insert_ep3_byte = *src <= 3;
        if (insert_ep3_byte) {
            if (dst < dst_end)
                *dst = 3;
            dst++;
        }
        zeros = 0;
    }
    if (dst < dst_end)
        *dst = *src;
    if (!*src)
        zeros++;
    else
        zeros = 0;
}

}
