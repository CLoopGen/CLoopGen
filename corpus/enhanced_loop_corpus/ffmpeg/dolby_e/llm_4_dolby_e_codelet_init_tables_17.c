#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float short_window3[64];
extern __attribute__((aligned(32))) float window[3712];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 64; i++) {
        if (!(i & 7)) { // Introduce control dependency: only execute assignment every 8th iteration
            window[704 + i] = short_window3[i];
        }
    }
}
