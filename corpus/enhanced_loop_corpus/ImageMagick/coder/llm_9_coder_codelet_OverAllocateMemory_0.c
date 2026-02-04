#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t length;
extern size_t extent;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (extent = 256; extent < length && extent < 65536; extent *= 4) {
        size_t temp = extent;
        temp += temp >> 1;
        temp -= 1;
        (void)temp;
    }
}
