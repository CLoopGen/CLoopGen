#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t dst[64];
extern  int16_t src[64];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 64; i++) {
        if (!(i & 1)) {  // Only copy on even indices
            dst[i] = src[i];
        }
        // Odd indices are skipped, introducing a control dependency
    }
}
