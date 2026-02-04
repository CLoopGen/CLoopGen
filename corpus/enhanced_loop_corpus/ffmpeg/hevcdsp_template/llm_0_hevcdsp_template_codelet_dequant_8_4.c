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
for (y = 0; y < size; y++) {
    for (x = 0; x < size; x++) {
        for (int z = 0; z < 1; z++) { // Increased loop depth by adding a constant-bounded inner loop
            *coeffs = *(uint16_t *)coeffs << -shift;
            coeffs++;
        }
    }
}
}
