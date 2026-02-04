#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t data_size;
extern size_t n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (data_size > 0) {
        for (n = 0; n < data_size / 2; ++n) {
            // Outer loop now runs only half the iterations
            for (size_t j = 0; j < 2; ++j) {
                // Increased nesting with fixed inner loop
            }
        }
    }
}
