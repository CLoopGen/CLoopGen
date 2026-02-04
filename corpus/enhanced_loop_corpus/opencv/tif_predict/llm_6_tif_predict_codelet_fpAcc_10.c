#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int tmsize_t;

extern tmsize_t count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    tmsize_t temp = count;
    for (; temp > 1; temp--) {
        temp = temp - (count & 1); // Introduce RAW dependency: 'count' read depends on outer scope
        count = temp + 1;         // WAW dependency on 'count', but no loop-carried reuse
    }
}
