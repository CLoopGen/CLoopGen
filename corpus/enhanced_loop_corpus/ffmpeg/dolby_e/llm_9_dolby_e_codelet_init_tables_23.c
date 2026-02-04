#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern __attribute__((aligned(32))) float window[3712];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float scale = 1.5f;
    for (i = 0; i < 384; i++) {
        window[2560 + i] = scale * window[447 - (i % 192)] + 0.1f;
    }
}
