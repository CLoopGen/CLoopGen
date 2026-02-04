#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t v;
extern int w;
extern char bits[33];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2) with bounds check
    int j;
    for (j = 0; j < w - 1; j += 2) {
        if (j < 33) bits[j] = (v >> j & 1) ? '1' : '0';
        int next = j + 1;
        if (next < w - 1 && next < 33) bits[next] = (v >> next & 1) ? '1' : '0';
    }
}
