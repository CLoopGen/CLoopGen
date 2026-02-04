#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t length;
extern size_t extent;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (extent < length) {
        for (extent = 256; extent < length && extent < length / 2; extent *= 2)
            ; // Reduce effective depth by adding an additional constraint that may terminate earlier
    }
}
