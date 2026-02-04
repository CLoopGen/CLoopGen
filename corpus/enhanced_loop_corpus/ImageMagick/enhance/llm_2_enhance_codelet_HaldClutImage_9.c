#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t length;
extern size_t level;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t idx = 2;
    for (level = 2; (idx * idx * idx) < length; level++, idx += 1)
        ;
}
