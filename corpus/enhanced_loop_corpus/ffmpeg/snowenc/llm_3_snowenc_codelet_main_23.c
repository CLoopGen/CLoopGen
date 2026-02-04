#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int buffer[2][65536];
extern short obuffer[65536];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated with simple transformation)
    for (i = 0; i < 256 * 256; i++) {
        int idx = (i * 7919) % 65536; // Large prime multiplier for pseudo-random access pattern
        obuffer[idx] = buffer[0][idx];
    }
}
