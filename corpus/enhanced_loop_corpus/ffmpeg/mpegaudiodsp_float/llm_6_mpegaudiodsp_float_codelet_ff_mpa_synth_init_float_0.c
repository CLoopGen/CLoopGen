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
    float temp[513] = {0}; // Local buffer to alter data dependencies
    for (i = 0; i < 257; i++) {
        float v;
        v = ff_mpa_enwindow[i];
        v *= 1. / (1LL << (16 + 23));
        temp[i] = v; // Store in temporary location first (introduces WAW dependency via temp)
        if ((i & 63) != 0)
            v = -v;
        if (i != 0)
            temp[512 - i] = v; // Eliminate direct write to window, break RAW/WAR on shared 'window'
    }
    // Now copy temp to window outside the main computation loop
    for (i = 0; i < 513; i++) {
        window[i] = temp[i];
    }
}
