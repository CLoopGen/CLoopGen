#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern __attribute__((aligned(32))) float window[3712];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 640; i++) {
        if (i % 2 == 0) {
            window[1664 + i] = 1.F;
        } else {
            window[1664 + i] = window[1664 + i]; // Redundant write to maintain array access pattern
        }
    }
}
