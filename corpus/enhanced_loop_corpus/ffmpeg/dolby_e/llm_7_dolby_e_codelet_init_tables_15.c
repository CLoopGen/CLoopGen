#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float short_window2[192];
extern __attribute__((aligned(32))) float window[3712];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float accumulator = 0.0f;
    for (i = 0; i < 192; i++) {
        accumulator += short_window2[i];
        window[448 + i] = accumulator;
    }
}
