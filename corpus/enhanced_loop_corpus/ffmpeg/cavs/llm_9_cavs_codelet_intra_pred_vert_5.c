#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *d;
extern ptrdiff_t stride;
extern int y;
extern uint64_t a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    const int unroll_factor = 4;
    for (y = 0; y < 8; y += unroll_factor) {
        int end = (y + unroll_factor > 8) ? 8 : y + unroll_factor;
        for (int i = y; i < end; ++i) {
            *((uint64_t *)(d + i * stride)) = a + i * 17;
        }
    }
}
