#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double levels[64];
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8; i++) {
        for (ssize_t j = 0; j < 8; j++) {
            levels[i * 8 + j] = 2.;
        }
    }
}
