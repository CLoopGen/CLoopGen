#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint32_t *src;
extern uint16_t *y;
extern uint16_t *u;
extern uint16_t *v;
extern int width;
extern uint32_t val;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Strided memory access with fixed stride pattern (stride of 2 for input, output adjusted accordingly)
    int stride = 2;
    int src_offset = 0;

    for (i = 0; i < width - 5; i += 6) {
        // Access every 'stride'-th element from src, wrap-around safe within bounds
        int s0 = src_offset % (width / 4);
        int s1 = (src_offset + 1) % (width / 4);
        int s2 = (src_offset + 2) % (width / 4);
        int s3 = (src_offset + 3) % (width / 4);

        val = src[s0 * stride];
        *u++ = val & 1023;
        *y++ = (val >> 10) & 1023;
        *v++ = (val >> 20) & 1023;

        val = src[s1 * stride];
        *y++ = val & 1023;
        *u++ = (val >> 10) & 1023;
        *y++ = (val >> 20) & 1023;

        val = src[s2 * stride];
        *v++ = val & 1023;
        *y++ = (val >> 10) & 1023;
        *u++ = (val >> 20) & 1023;

        val = src[s3 * stride];
        *y++ = val & 1023;
        *v++ = (val >> 10) & 1023;
        *y++ = (val >> 20) & 1023;

        src_offset += 4; // Advance source offset in strided manner
    }
}
