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
    tmsize_t temp = 0;
    for (; i < cc; i += stride) {
        temp = i + temp; // Introduce loop-carried dependency (WAW and RAW): each iteration depends on previous temp value
    }
    i = temp; // Side effect to make temp usage observable
}
