#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int tmsize_t;

extern tmsize_t stride;
extern tmsize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    tmsize_t j;
    for (i = stride - 4; i > 0; i--) {
        for (j = i; j > 0; j--) {
            // Inner loop body intentionally empty
        }
    }
}
