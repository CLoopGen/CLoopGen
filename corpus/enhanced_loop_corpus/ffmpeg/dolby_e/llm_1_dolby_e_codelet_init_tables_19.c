#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern __attribute__((aligned(32))) float window[3712];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 32; i++) {
    window[960 + i] = window[i];
    window[960 + i + 32] = window[i + 32];
    window[960 + i + 64] = window[i + 64];
    window[960 + i + 96] = window[i + 96];
}
}
