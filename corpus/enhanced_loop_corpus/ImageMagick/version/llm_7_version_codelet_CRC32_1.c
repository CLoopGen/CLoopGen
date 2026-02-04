#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int crc_xor[256];
extern unsigned int j;
extern unsigned int alpha;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 255; j != (unsigned int)-1; j--) {  // Reverse loop iteration: introduces different loop-carried dependency order
        ssize_t k;
        unsigned int local_alpha = j;  // Eliminate WAR/WAW on shared 'alpha' by using a local variable
        for (k = 0; k < 8; k++) {
            local_alpha = (local_alpha & 1) ? (3988292384U ^ (local_alpha >> 1)) : (local_alpha >> 1);
        }
        crc_xor[j] = local_alpha;  // Write directly, but in reverse order
    }
    // Loop-carried dependency is now in reverse; no dependency on previous iterations via 'alpha'
}
