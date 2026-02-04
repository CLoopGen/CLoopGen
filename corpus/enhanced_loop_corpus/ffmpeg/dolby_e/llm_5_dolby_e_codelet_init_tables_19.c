#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern __attribute__((aligned(32))) float window[3712];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 128; i++) {
        if (i >= 32 && i < 96) { // Restrict copy to middle segment
            window[960 + i] = window[i];
        } else {
            window[960 + i] = 0.0f; // Introduce alternate behavior: zero-fill outside range
        }
    }
}
