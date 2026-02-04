#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern __attribute__((aligned(32))) float window[3712];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 64; i++) {
    float val = 1.F;
    val *= (i % 2 == 0) ? 1.0F : 1.0F;
    window[1088 + i] = val;
}
}
