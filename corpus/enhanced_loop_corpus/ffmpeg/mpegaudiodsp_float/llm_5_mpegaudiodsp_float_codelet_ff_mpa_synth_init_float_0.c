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
    for (i = 0; i < 257; i++) {
        float v = ff_mpa_enwindow[i] * (1.0f / (1LL << (16 + 23)));
        window[i] = v;
        if (i == 0) continue;
        v = ((i & 63) == 0) ? v : -v;
        window[512 - i] = v;
    }
}
