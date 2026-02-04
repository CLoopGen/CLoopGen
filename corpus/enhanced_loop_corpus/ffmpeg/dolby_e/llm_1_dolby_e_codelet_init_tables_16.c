#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern __attribute__((aligned(32))) float window[3712];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8; i++) {
        for (int k = 0; k < 8; k++) {
            int idx = i * 8 + k;
            window[640 + idx] = window[63 - idx];
        }
    }
}
