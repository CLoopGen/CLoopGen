#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern __attribute__((aligned(32))) float window[3712];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 96; i++) {
        float val1 = window[64 + i];
        float val2 = window[160 + i];
        float val3 = window[256 + i];
        window[768 + i] = val1 * val2 + val3;
        window[864 + i] = val3 * val1 + val2;
    }
}
