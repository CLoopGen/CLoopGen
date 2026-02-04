#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *d;
extern uint8_t *left;
extern ptrdiff_t stride;
extern int y;
extern uint64_t a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < 4; y++) {
    uint8_t val1 = left[y + 1];
    uint8_t val2 = left[y + 2];
    a = (val1 * val1 + val2 * 36170086419038336ULL) * 2;
    *((uint64_t *)(d + y * stride)) = a;
    a = (val2 * val2 + val1 * 36170086419038336ULL) * 2;
    *((uint64_t *)(d + (y + 1) * stride)) = a;
}
}
