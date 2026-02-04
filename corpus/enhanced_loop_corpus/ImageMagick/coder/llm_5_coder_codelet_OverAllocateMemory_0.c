#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t length;
extern size_t extent;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (extent = (length <= 256) ? length : 256; extent < length; extent = (extent < length / 2) ? extent * 2 : extent + 1)
        ;
}
