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
    tmsize_t outer_i;
    for (outer_i = 0; outer_i < cc; outer_i += stride * 2) {
        i = outer_i;
        for (; i < outer_i + stride && i < cc; i++) {
        }
    }
}
