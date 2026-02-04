#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern __attribute__((aligned(32))) float window[3712];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 128; i += 2) {
        window[640 + i] = window[63 - i];
        if (i + 1 < 64) {
            window[640 + i + 1] = window[63 - i - 1];
        }
    }
}
