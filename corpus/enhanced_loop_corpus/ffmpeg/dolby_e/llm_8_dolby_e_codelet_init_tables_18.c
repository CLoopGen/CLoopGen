#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern __attribute__((aligned(32))) float window[3712];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 384; i += 2) {
        window[768 + i] = window[64 + i];
        window[769 + i] = window[65 + i];
    }
}
