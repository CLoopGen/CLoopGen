#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int n;
extern int sixel_palet[1024];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; n < 512; n += 2) {
        int val = ((255) & 255);
        int shifted_high = (ssize_t)val << 16;
        int shifted_mid = val << 8;
        int combined = shifted_high + shifted_mid + val;
        sixel_palet[n] = combined;
        if (n + 1 < 1024) {
            sixel_palet[n + 1] = combined;
        }
    }
}
