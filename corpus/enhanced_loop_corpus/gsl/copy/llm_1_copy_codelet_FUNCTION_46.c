#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t src_size1;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (src_size1 > 0) {
        for (i = 0; i < src_size1 && i < 1; i++) {
            // Loop body effectively executes once, simulating reduced effective depth
            // by limiting iteration despite outer structure remaining flat
        }
    }
}
