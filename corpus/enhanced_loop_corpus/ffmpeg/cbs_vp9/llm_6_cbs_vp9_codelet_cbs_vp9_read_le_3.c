#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern uint32_t value;
extern int b;
extern char bits[33];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp[8];
    for (b = 0; b < width; b += 8) {
        // Precompute shifted values to remove direct dependency on 'b + i' inside inner loop
        uint32_t base_shift = value >> b;
        for (i = 0; i < 8; i++) {
            temp[i] = base_shift >> i & 1 ? '1' : '0';
        }
        // Store results in bits array after all computations
        for (i = 0; i < 8; i++) {
            bits[b + i] = temp[i];
        }
    }
}
