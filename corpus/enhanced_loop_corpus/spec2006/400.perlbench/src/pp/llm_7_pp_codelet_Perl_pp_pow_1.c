#include <stdio.h>

#include <inttypes.h>

typedef unsigned long UV;

typedef double NV;

extern UV power;
extern NV result;
extern NV base;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    UV mask = (UV)1;
    int shift = 0;

    for (; shift < (int)(8 * sizeof(UV)) && mask != 0; mask <<= 1, shift++) {
        UV bit = mask & power;
        if (bit) {
            result *= base;
            power -= bit;
        }
        if (power == 0)
            break;
        // Eliminate WAW on 'base' by deferring update until next iteration
        NV next_base = base * base;
        base = next_base;
        n++;
    }
}
