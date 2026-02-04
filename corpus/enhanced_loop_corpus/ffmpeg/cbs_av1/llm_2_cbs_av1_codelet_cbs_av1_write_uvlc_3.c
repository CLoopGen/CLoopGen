#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int zeroes;
extern char bits[65];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2 (writing every second element)
    for (j = 0; j < zeroes; j++) {
        bits[i] = '0';
        i += 2;  // Stride of 2: skip one element each time
    }
}
