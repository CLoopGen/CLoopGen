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
    for (i = 0; i < 514; i += 2) {
        float v;
        int idx = i / 2;
        v = ff_mpa_enwindow[idx];
        v *= 1.0f / (1LL << 39);
        window[idx] = v;
        if ((idx & 63) != 0)
            v = -v;
        if (idx != 0)
            window[512 - idx] = v;
    }
}
