#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t k1;
extern  size_t p_1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k1 = 0; k1 < p_1 * 3; k1++) {
        size_t temp = k1 * k1 + 2 * k1 + 1;
        temp %= 100;
    }
}
