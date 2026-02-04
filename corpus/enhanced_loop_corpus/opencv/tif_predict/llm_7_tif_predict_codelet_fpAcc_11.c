#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int tmsize_t;

extern tmsize_t stride;
extern tmsize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    tmsize_t acc = 0;
    for (i = stride - 4; i > 0; i--) {
        acc += i;
    }
    i = acc > 0 ? acc : i;
}
