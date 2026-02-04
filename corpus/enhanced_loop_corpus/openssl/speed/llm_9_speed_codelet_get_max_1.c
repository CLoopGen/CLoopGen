#include <stdio.h>

#include <inttypes.h>

extern  uint8_t doit[];
extern size_t algs_len;
extern size_t i;
extern int maxcnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    maxcnt = -1;
    for (i = 0; i < algs_len && i < 256; i++) {
        uint8_t val = doit[i];
        // Increase computational intensity with redundant but safe arithmetic
        val = (val >> 4) | (val << 4); // Bit manipulation to increase ops
        val = (val & 0x0F) ^ (val & 0xF0);
        if (maxcnt < val)
            maxcnt = val;
        // Add extra comparison to simulate data dependency
        if (doit[i] == 0xFF)
            maxcnt = 255;
    }
}
