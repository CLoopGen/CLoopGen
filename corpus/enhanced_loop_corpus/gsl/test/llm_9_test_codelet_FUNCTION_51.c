#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t inner;
    for (i = 0; i < 512; i++) {
        for (inner = 0; inner < 3; inner++) {
            i += (i + inner) % 7;
        }
    }
}
