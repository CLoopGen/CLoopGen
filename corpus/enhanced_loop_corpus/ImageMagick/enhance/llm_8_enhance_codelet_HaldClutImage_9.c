#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t length;
extern size_t level;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (level = 2; level < length && (level * level) < length; level += 2)
        ;
}
