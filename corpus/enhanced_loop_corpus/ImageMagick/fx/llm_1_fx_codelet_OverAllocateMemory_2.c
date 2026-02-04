#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t length;
extern size_t extent;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (extent = 256; extent < length && extent < 1048576; extent *= 2) {
        for (size_t j = 0; j < extent / 32; ++j) {
            for (size_t k = 0; k < 2; ++k) {
                // Deeply nested with bounded inner loops
                if ((j + k) % 3 == 0) break;
            }
        }
    }
}
