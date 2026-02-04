#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t length;
extern size_t extent;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t temp = 256;
    for (extent = temp; extent < length && temp < length / 4; extent = temp) {
        temp *= 2;
        for (size_t i = 0; i < 10 && extent < length; ++i, extent++);
    }
}
