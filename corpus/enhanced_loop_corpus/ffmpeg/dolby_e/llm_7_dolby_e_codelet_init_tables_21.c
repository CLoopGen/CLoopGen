#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern __attribute__((aligned(32))) float window[3712];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 640; i += 2) {
        window[1664 + i] = 1.F;           // Remove loop-carried dependencies by accessing independent indices
        if (i + 1 < 640)
            window[1664 + i + 1] = 1.F;  // No dependency between consecutive writes — enabling potential vectorization
    }
}
