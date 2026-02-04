#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t length;
extern size_t level;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t temp_level = 2;
    for (level = 2; (temp_level * temp_level * temp_level) < length; temp_level++) {
        level = temp_level;
    }
}
