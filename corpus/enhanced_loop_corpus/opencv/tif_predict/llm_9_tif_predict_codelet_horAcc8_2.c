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
    tmsize_t step = stride * 2;
    for (; i < cc; i += step) {
        i = (i + 1) * 2;
        if (i >= cc) break;
        i = (i + 1) / 2;
    }
}
