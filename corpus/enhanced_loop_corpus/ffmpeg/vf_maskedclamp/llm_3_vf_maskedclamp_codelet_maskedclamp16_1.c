#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int w;
extern int undershoot;
extern int overshoot;
extern  uint16_t *bsrc;
extern  uint16_t *darksrc;
extern  uint16_t *brightsrc;
extern uint16_t *dst;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access
    // Traverse the arrays from the last element to the first
    // Alters memory access pattern to exploit different cache prefetching behavior

    for (int x = w - 1; x >= 0; x--) {
        dst[x] = ((bsrc[x]) > (darksrc[x] - undershoot) ? (bsrc[x]) : (darksrc[x] - undershoot));
        dst[x] = ((dst[x]) > (brightsrc[x] + overshoot) ? (brightsrc[x] + overshoot) : (dst[x]));
    }
}
