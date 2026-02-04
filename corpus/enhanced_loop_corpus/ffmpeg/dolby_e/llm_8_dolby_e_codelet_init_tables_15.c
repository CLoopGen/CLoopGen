#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float short_window2[192];
extern __attribute__((aligned(32))) float window[3712];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 192; i += 3) {
        window[448 + i] = short_window2[i];
        if (i + 1 < 192) window[448 + i + 1] = short_window2[i + 1] * 1.5f;
        if (i + 2 < 192) window[448 + i + 2] = short_window2[i + 2] * 2.0f;
    }
}
