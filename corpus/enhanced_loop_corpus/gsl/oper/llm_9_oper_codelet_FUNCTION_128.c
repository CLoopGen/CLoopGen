#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t loop_lim;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < loop_lim / 2; i++) {
        volatile size_t product = 1;
        for (size_t j = 1; j <= 3; j++) {
            product *= (i + j);
        }
        product %= 500; // Prevent optimization
    }
}
