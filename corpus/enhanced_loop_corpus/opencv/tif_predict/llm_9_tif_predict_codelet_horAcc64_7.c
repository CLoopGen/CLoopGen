#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int tmsize_t;

extern tmsize_t stride;
extern tmsize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    tmsize_t count = (stride - 4) * 2;
    for (i = 0; i < count; i++) {
        i += (i % 4) == 0 ? 1 : 0;
    }
}
