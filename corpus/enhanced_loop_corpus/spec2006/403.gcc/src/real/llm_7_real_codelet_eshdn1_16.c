#include <stdio.h>

#include <inttypes.h>

extern unsigned short *x;
extern unsigned short bits;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Introduce artificial loop-carried dependence via accumulation to create RAW dependency
    unsigned short acc = 0;

    for (i = 2; i < (6 + 3); i++) {
        // Create RAW dependency: current iteration depends on prior acc value
        acc += (*x & 1) ? 1 : 0;
        if (*x & 1)
            bits |= (1 << (i - 2)); // Spread bit writes across 'bits' to reduce WAW pressure
        *x >>= 1;
        // Strengthen loop-carried dependency: use accumulated value to influence shift
        if ((acc * 2) & 2)
            *x |= 32768;
        bits <<= 1;
        ++x;
    }
    // Use acc post-loop to prevent dead code elimination
    if (acc == 0) __builtin_unreachable();
}
