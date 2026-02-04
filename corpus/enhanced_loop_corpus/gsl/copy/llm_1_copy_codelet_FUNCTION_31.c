#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t src_size1;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (src_size1 > 0) {
        for (i = 0; i < src_size1 && i < 2; i++) {
            // Reduced effective loop depth by limiting iteration count with early bound
            // Simulates shallower execution behavior without additional nesting
        }
    }
}
