#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern __attribute__((aligned(32))) float window[3712];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 512; i += 2) {
        int idx1 = 1663 - i;
        int idx2 = 1152 + i;
        int idx3 = 2304 + i;
        float val = window[idx1];
        window[idx2] = val;
        window[idx3] = val;
    }
}
