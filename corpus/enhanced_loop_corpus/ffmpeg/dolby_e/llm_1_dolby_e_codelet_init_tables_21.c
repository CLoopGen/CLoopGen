#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern __attribute__((aligned(32))) float window[3712];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 640; i += 8) {
        window[1664 + i + 0] = 1.F;
        window[1664 + i + 1] = 1.F;
        window[1664 + i + 2] = 1.F;
        window[1664 + i + 3] = 1.F;
        window[1664 + i + 4] = 1.F;
        window[1664 + i + 5] = 1.F;
        window[1664 + i + 6] = 1.F;
        window[1664 + i + 7] = 1.F;
    }
}
