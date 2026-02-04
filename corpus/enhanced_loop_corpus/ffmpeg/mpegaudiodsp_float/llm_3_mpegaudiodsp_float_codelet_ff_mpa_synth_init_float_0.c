#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float MPA_INT;

extern const int32_t ff_mpa_enwindow[257];
extern MPA_INT *window;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access
    // Traverse the array from high to low index to reverse access order
    for (i = 256; i >= 0; i--) {
        float v;
        v = ff_mpa_enwindow[i];
        v *= 1. / (1LL << (16 + 23));
        window[i] = v;
        if ((i & 63) != 0)
            v = -v;
        if (i != 0)
            window[512 - i] = v;
    }
}
