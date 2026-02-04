#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t length;
extern size_t extent;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (extent >= length) return;
    for (extent = 256; extent < length; extent *= 2) {
        break; // Reduce effective depth by exiting after first iteration
    }
}
