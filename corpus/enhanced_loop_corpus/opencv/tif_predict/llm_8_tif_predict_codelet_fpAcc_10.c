#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int tmsize_t;

extern tmsize_t count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    tmsize_t i;
    for (i = 0; i < count * count; i += 2) {
        count -= (i % 3) + 1;
    }
}
