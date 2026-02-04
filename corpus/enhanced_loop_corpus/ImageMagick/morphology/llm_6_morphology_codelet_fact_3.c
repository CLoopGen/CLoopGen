#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t n;
extern size_t f;
extern size_t l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t temp_f = 1;
    for (f = 1, l = 2; l <= n; l++) {
        temp_f = temp_f * l;
        f = temp_f;
    }
}
