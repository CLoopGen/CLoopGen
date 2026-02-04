#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float start_window[192];
extern __attribute__((aligned(32))) float window[3712];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse sequential access — copy elements from the end to the beginning
    for (i = 191; i >= 0; i--) {
        window[256 + i] = start_window[i];
    }
}
