#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern __attribute__((aligned(32))) float window[3712];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 32; i++) {
        float val = window[63 - i] * 1.5f;
        window[640 + i] = val;
        window[640 + i + 32] = val * 0.8f;
    }
}
