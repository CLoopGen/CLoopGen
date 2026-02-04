#include <stdio.h>

#include <inttypes.h>

extern int count;
extern unsigned int parts[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (i = 0; i < (((8 * 8) / 8) * 2); i += 2) {
        parts[i]     = 0;
        parts[i + 1] = parts[i]; // Introduce RAW (read-after-write) dependency: read parts[i] just written
    }
    // Handle potential odd-sized array if needed, but size is fixed at 16 elements (even)
    // No loop-carried dependency across iterations beyond adjacent pairs
}
