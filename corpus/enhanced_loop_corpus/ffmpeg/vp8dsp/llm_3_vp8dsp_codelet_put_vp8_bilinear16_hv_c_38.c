#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern ptrdiff_t sstride;
extern int h;
extern int a;
extern int b;
extern int x;
extern int y;
extern uint8_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access - process every 2nd element first, then fill in
    uint8_t *src_local = src;
    uint8_t *tmp_local = tmp;
    for (y = 0; y < h + 1; y++) {
        const uint8_t *s = src_local;
        uint8_t *t = tmp_local;
        // First pass: even indices using stride of 2
        for (x = 0; x < 16; x += 2)
            t[x] = (a * s[x] + b * s[x + 1] + 4) >> 3;
        // Second pass: odd indices
        for (x = 1; x < 15; x += 2)
            t[x] = (a * s[x] + b * s[x + 1] + 4) >> 3;
        // Handle boundary if needed (x=15 already covered by second loop condition)
        tmp_local += 16;
        src_local += sstride;
    }
}
