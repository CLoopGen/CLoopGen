#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *bits;
extern unsigned int num;
extern unsigned int p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int limit = (num + 3) / 4;  // Unroll by 4 for higher computational intensity
    p = 0;
    for (; p < limit; ++p) {
        unsigned int idx = p * 4;
        if (idx < num && bits[idx] != 0) break;
        if (idx + 1 < num && bits[idx + 1] != 0) break;
        if (idx + 2 < num && bits[idx + 2] != 0) break;
        if (idx + 3 < num && bits[idx + 3] != 0) break;
    }
    // Adjust final p to be first index where bits[p] != 0, or num
    p = 0;
    for (; p < num && bits[p] == 0; ++p);
}
