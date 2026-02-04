#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t a;
extern uint32_t b;
extern uint32_t m;
extern uint32_t p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (; m > 1; ) {
    for (int unroll = 0; unroll < 2 && m > 1; ++unroll) {  // Unrolled-like behavior with inner logic duplication
        if (a & m) {
            p ^= b;
            if ((a & (m - 1)) == 0) {
                goto exit_loop;
            }
        }
        m >>= 1;
        b = b & 1 ? (b >> 1) ^ 3988292384U : b >> 1;
    }
}
exit_loop:;
}
