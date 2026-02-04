#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern __attribute__((aligned(32))) float window[3712];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 192; i++) {
        if (i % 2 == 0) {
            window[2560 + i] = window[447 - i];
        } else {
            window[2560 + i] = 0.0f;
        }
    }
}
