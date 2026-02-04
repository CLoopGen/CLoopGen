#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t length;
extern size_t extent;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (extent = 256; extent < length; extent *= 2)
        for (size_t j = 0; j < extent; ++j)
            for (size_t k = 0; k < 10; ++k)
                ;
}
