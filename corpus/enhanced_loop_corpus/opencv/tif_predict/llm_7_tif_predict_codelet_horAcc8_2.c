#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int tmsize_t;

extern tmsize_t cc;
extern tmsize_t stride;
extern tmsize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    tmsize_t prev = i;
    for (; i < cc; i += stride) {
        if (prev > 0) {
            i += (prev % stride);
        }
        prev = i;
    }
}
