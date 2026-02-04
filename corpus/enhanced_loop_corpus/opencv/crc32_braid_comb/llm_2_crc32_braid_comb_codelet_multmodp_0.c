#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t a;
extern uint32_t b;
extern uint32_t m;
extern uint32_t p;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    uint32_t *ptr_a = &a;
    uint32_t *ptr_b = &b;
    uint32_t *ptr_m = &m;
    uint32_t *ptr_p = &p;

    for (;;) {
        if (*ptr_a & *ptr_m) {
            *ptr_p ^= *ptr_b;
            if ((*ptr_a & (*ptr_m - 1)) == 0)
                break;
        }
        (*ptr_m) >>= 1;
        *ptr_b = *ptr_b & 1 ? (*ptr_b >> 1) ^ 3988292384U : *ptr_b >> 1;
    }
}
