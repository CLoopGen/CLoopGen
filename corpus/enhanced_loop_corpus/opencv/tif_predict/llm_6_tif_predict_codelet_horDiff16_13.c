#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int tmsize_t;

extern tmsize_t stride;
extern tmsize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    tmsize_t temp = 0;
    for (i = stride - 4; i > 0; i--) {
        temp += i * stride;
    }
    // Introduces a loop-carried dependency (WAW on temp) and a RAW (read i before write to temp)
    // Eliminates any previous independent behavior by making each iteration depend on the accumulated value.
}
