#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern __attribute__((aligned(32))) float window[3712];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float a = 0.5F, b = 2.0F;
    for (i = 0; i < 320; i++) {
        float temp = a * b;
        window[1664 + 2*i]     = temp;
        window[1664 + 2*i + 1] = temp;
        a = a + 0.1F;
        b = b - 0.1F;
    }
}
