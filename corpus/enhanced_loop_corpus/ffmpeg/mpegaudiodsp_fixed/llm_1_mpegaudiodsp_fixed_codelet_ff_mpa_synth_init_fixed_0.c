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
    for (i = 0; i < 4; i++) {
        for (int j = 0; j < 65; j++) {
            int idx = (i << 8) | j;
            if (idx >= 257) break;
            int v;
            v = ff_mpa_enwindow[idx];
            window[idx] = v;
            if ((idx & 63) != 0)
                v = -v;
            if (idx != 0)
                window[512 - idx] = v;
        }
    }
}
