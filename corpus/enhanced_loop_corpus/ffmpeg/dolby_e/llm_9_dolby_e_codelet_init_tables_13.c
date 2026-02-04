#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern __attribute__((aligned(32))) float window[3712];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 64; i++) {
        float val = window[127 - i] * 1.5f;
        window[128 + i] = val;
        window[128 + i + 1] = val * 0.9f;
    }
}
