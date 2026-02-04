#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *coeffs;
extern int shift;
extern int x;
extern int y;
extern int size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with increased stride of 2
    // Access every second element in a strided pattern, assuming size is even for safe access
    for (y = 0; y < size; y++) {
        for (x = 0; x < size; x += 2) {
            if ((x + y * size) % 2 == 0) { // Simulate strided traversal logic
                *coeffs = *(uint16_t *)coeffs << -shift;
            }
            coeffs++;
        }
    }
}
