#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float short_window3[64];
extern __attribute__((aligned(32))) float window[3712];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 64; i += 4) {
        window[704 + i]     = short_window3[i];
        window[704 + i + 1] = short_window3[i + 1];
        window[704 + i + 2] = short_window3[i + 2];
        window[704 + i + 3] = short_window3[i + 3];
    }
}
