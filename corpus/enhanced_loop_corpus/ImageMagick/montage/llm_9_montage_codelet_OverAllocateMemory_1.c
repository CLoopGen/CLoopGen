#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t length;
extern size_t extent;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t i;
    for (extent = 256; extent < length; extent *= 2) {
        for (i = 0; i < 10 && extent + i < length; ++i) {
            // Perform dummy operations to increase computational intensity
            extent += i % 2;
        }
    }
}
