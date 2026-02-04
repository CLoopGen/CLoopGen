#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 512; i++) {
        size_t k;
        for (k = 0; k < 3; k++) {
            i += (i + k) % 7;
        }
    }
}
