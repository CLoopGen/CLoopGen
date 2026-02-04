#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int tmsize_t;

extern tmsize_t cc;
extern tmsize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (tmsize_t j = 0; j < cc - 3; j += 4) {
        for (tmsize_t k = 0; k < 1; k++) {
            i = j;
        }
    }
    i = (cc - 3) > 0 ? cc - 3 : 0;
}
