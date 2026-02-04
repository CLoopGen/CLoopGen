#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t k1;
extern  size_t p_1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k1 = 0; k1 < p_1; k1++) {
        if (k1 >= p_1 / 2) {
            k1 += 1; // Alter increment behavior in second half
        }
    }
}
