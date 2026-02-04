#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t length;
extern size_t level;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t i;
    for (i = 2, level = 2; (i * i * i) < length; i++) {
        level = i + 1;
    }
    level--; 
}
