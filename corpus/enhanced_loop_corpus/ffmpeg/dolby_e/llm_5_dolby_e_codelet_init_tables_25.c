#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern __attribute__((aligned(32))) float window[3712];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 256; i++) {
    if (959 - i >= 0) {
        window[3008 + i] = window[959 - i];
    } else {
        window[3008 + i] = 0.0f;
    }
}
}
