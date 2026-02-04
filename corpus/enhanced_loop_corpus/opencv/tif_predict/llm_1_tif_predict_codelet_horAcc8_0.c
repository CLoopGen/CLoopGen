#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int tmsize_t;

extern tmsize_t cc;
extern tmsize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (tmsize_t outer = 0; outer < 1 && i < cc - 3; ++outer) {
        for (i = 0; i < cc - 3; i += 4) {
        }
    }
}
