#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t length;
extern size_t extent;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (extent = 256; extent < length; extent *= 2) {
        for (size_t i = 0; i < 4; ++i) {
            // Simulate some nested work without side effects
            continue;
        }
    }
}
