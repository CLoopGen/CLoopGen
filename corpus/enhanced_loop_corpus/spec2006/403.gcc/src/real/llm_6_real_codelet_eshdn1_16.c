#include <stdio.h>

#include <inttypes.h>

extern unsigned short *x;
extern unsigned short bits;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    unsigned short temp_bits = bits; // Introduce local copy to break WAW dependency on 'bits'
    unsigned short *local_x = x;     // Local pointer to manage pointer update separately

    for (i = 2; i < (6 + 3); i++) {
        // Eliminate loop-carried dependency on *x by batching shift and conditional set
        unsigned short val = *local_x;
        if (val & 1)
            temp_bits |= 1;
        val >>= 1;
        if (temp_bits & 2)
            val |= 32768;
        *local_x = val; // Write back modified value
        temp_bits <<= 1;
        local_x++; // Update pointer after use to break WAR on 'x'
    }
    // Commit side effects to global state after loop
    bits = temp_bits;
    x = local_x;
}
