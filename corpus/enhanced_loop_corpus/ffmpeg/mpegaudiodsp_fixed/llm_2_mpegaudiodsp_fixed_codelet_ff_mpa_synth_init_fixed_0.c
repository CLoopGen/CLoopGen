#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t MPA_INT;

extern const int32_t ff_mpa_enwindow[257];
extern MPA_INT *window;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with forward and backward stepping
    for (i = 0; i < 257; i += 1) {
        int v;
        int idx = i;
        v = ff_mpa_enwindow[idx];
        window[idx] = v;
        if ((i & 63) != 0)
            v = -v;
        if (i != 0) {
            int mirror_idx = 512 - idx;
            window[mirror_idx] = v;
        }
    }
}
