#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern __attribute__((aligned(32))) float window[3712];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 64; i++) {
        float val = window[i] + window[i + 32] - window[i + 64];
        window[960 + i] = val * 0.5f;
        window[992 + i] = val * 2.0f;
    }
}
