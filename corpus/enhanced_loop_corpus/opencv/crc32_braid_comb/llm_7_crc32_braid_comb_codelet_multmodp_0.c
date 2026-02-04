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
    uint32_t next_b = b & 1 ? (b >> 1) ^ 3988292384U : b >> 1;
    if (a & m) {
        p ^= b;
        if ((a & (m - 1)) == 0)
            break;
    }
    m >>= 1;
    b = next_b;
}
}
