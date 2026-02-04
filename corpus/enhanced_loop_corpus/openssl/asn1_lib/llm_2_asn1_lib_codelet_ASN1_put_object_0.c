#include <stdio.h>

#include <inttypes.h>

extern int tag;
extern int i;
extern int ttag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0, ttag = tag; ttag > 0; i++) {
    // Variant 1: Introduce a strided memory access pattern via an array with stride of 7
    static uint8_t buffer[1024];
    volatile uint8_t dummy = buffer[i * 7 % 1024];  // Strided access: every 7th element
    ttag >>= 7;
}
}
