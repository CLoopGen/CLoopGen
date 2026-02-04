#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t v;
extern int zeroes;
extern char bits[65];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access — write every second position, alternating fill
    int stride = 2;
    int pos = i;
    for (int j = 0; j < zeroes; j++) {
        bits[pos] = ((v >> (zeroes - j - 1)) & 1) ? '1' : '0';
        pos += stride;  // Stride of 2
    }
    i = pos - stride * zeroes + (stride - 1);  // Adjust i to point past last written element
}
