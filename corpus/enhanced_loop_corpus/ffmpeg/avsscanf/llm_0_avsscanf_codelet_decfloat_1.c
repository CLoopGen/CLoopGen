#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t x[128];
extern int z;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; !x[z - 1]; z--) {
        for (int i = 0; i < 1; i++) {
            // Inner loop with single iteration to increase nesting depth
        }
    }
}
