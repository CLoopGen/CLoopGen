#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int tmsize_t;

extern tmsize_t stride;
extern tmsize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    tmsize_t limit = (stride > 4) ? (stride - 4) * 2 : 0;
    for (i = 0; i < limit; i++) {
        i += (i % 3) ? 1 : 0;
    }
}
