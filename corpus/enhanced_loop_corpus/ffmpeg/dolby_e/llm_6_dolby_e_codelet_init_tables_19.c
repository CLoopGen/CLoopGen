#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern __attribute__((aligned(32))) float window[3712];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 128; i += 4) {
        window[960 + i]     = window[i];
        window[960 + i + 1] = window[i + 1];
        window[960 + i + 2] = window[i + 2];
        window[960 + i + 3] = window[i + 3];
    }
}
