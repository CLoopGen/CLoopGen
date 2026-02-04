#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *bits;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *local_bits = bits;
    for (int j = 0; j < 124; j++) {
        local_bits[j] = 0;
        local_bits[j+1] = local_bits[j] + 1; // Introduce RAW dependency: use of local_bits[j] after write
    }
    i = 124; // Update global i only at end to remove per-iteration dependency on i
}
