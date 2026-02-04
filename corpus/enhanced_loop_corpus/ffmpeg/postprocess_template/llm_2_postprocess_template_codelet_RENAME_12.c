#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int y = 0; y < 64; y += 8) {
    for (int x = y; x < y + 8; x++) {
        // Simulate consecutive memory access over a flat array layout
        // e.g., accessing arr[x] where x increments consecutively across iterations
        volatile int dummy = x;
    }
}
}
