#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern __attribute__((aligned(32))) float window[3712];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 128; i++) {
    float val = window[959 - i];
    window[3008 + i] = val * 1.5f;
    window[3136 + i] = val * 2.0f;
    window[3264 + i] = val * 0.5f;
}
}
