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
        uint32_t mask_check = a & m;
        uint32_t lower_bits_zero = ((a & (m - 1)) == 0);
        if (mask_check) {
            p ^= b;
        }
        if (lower_bits_zero || !mask_check) {
            if (lower_bits_zero)
                break;
        } else {
            m >>= 1;
            b = b & 1 ? (b >> 1) ^ 3988292384U : b >> 1;
        }
        m >>= 1;
        b = b & 1 ? (b >> 1) ^ 3988292384U : b >> 1;
    }
}
