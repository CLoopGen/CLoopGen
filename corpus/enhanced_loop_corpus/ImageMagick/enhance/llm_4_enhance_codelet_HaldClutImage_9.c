#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t length;
extern size_t level;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (level = 2; (level * level) < length && (level * level * level) < length; level++)
        ;
}
