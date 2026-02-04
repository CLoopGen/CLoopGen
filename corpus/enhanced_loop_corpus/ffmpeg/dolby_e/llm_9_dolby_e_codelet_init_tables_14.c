#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float start_window[192];
extern __attribute__((aligned(32))) float window[3712];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float scale = 1.5f;
    for (i = 0; i < 384; i++) {
        int src_idx = i % 192;
        int dst_idx = 256 + i % 192;
        window[dst_idx] = start_window[src_idx] * scale + 0.1f;
        scale *= 1.001f;
    }
}
