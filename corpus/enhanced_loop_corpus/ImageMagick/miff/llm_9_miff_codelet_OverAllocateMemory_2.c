#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t length;
extern size_t extent;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t temp = 256;
    for (extent = temp; extent < length && temp < 1000; extent++, temp += 8)
        ;
}
