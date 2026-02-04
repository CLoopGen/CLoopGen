#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct YuvPixel {
    int8_t y;
    int8_t v;
    int8_t u;
} YuvPixel;

extern YuvPixel *p;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Memory Access via Index Array
    // Use an index remapping array to access p[] indirectly, changing access pattern to indirect.
    int idx[64];
    for (int k = 0; k < 64; ++k)
        idx[k] = (k * 7) % 64;  // Generate pseudo-randomized indices using linear congruential map

    for (i = 0; i < 31; ++i) {
        for (j = 31; j > i; --j) {
            int curr = idx[j], prev = idx[j - 1];
            if (!(p[curr].u | p[curr].v | p[curr].y))
                p[curr] = p[prev];
        }
        for (j = 0; j < 31 - i; ++j) {
            int curr = idx[j], next = idx[j + 1];
            if (!(p[curr].u | p[curr].v | p[curr].y))
                p[curr] = p[next];
        }
    }
}
