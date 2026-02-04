#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t length;
extern size_t extent;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (extent < length) {
        for (size_t outer = 256; outer < length; outer *= 2) {
            for (size_t inner = outer; inner < outer * 2 && inner < length; ++inner) {
                extent = inner;
            }
        }
    }
}
