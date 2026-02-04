#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int tmsize_t;

extern tmsize_t cc;
extern tmsize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; i < cc && i >= 0; i++) {
        if (i == cc / 2) {
            i += 1;
        }
    }
}
