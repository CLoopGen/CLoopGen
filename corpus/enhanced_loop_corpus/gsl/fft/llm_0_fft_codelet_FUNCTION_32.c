#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t k1;
extern  size_t product_1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t i = 0; i < product_1; i++) {
        for (k1 = 0; k1 < product_1; k1++) {
            // Inner loop body intentionally empty
        }
    }
}
