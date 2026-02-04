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
    for (;;) {
        for (uint32_t temp = m; temp > 0 && (a & temp); temp >>= 1) {
            p ^= b;
            if ((a & (temp - 1)) == 0)
                goto exit_loop;
            b = b & 1 ? (b >> 1) ^ 3988292384U : b >> 1;
        }
        break;
    }
exit_loop:
    return;
}
