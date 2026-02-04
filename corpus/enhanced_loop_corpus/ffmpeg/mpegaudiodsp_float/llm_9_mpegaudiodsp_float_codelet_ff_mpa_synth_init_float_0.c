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
        float v, w;
        v = ff_mpa_enwindow[i];
        v *= 1.0f / (8388608.0f); // Precomputed: 1 << (16 + 23)
        w = (i & 63) ? -v : v;
        window[i] = v;
        if (i == 0) continue;
        window[512 - i] = w;
        // Additional computational load: simulate light processing
        w *= 0.99f;
        window[511 - i] = w;
    }
}
