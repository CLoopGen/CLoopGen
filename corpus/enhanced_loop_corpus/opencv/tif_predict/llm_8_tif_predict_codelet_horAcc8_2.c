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
    tmsize_t j;
    for (; i < cc; i += stride) {
        for (j = 0; j < 5; ++j) {
            i += (i + 2) * 3 - j;
        }
    }
}
