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
for (i = 0; i < 257; i += 4) {
    int v0, v1, v2, v3;
    v0 = ff_mpa_enwindow[i];
    v1 = ff_mpa_enwindow[i+1];
    v2 = ff_mpa_enwindow[i+2];
    v3 = ff_mpa_enwindow[i+3];

    window[i] = v0;
    window[i+1] = v1;
    window[i+2] = v2;
    window[i+3] = v3;

    if ((i & 63) != 0) {
        v0 = -v0;
        v1 = -v1;
        v2 = -v2;
        v3 = -v3;
    }

    if (i != 0) {
        window[512 - i] = v0;
        window[512 - (i+1)] = v1;
        window[512 - (i+2)] = v2;
        window[512 - (i+3)] = v3;
    }
}
}
