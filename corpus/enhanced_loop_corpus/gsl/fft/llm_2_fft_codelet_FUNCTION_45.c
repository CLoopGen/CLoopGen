#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t k;
extern size_t k1;
extern  size_t q;
extern  size_t product_1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 1; k < (q + 1) / 2; k++) {
        for (k1 = 0; k1 < product_1; k1++) {
            // Introduce strided memory access pattern via synthetic array usage
            volatile char dummy[1024];
            size_t index = (k * 7) % 1000; // Strided access with stride-like modulus
            dummy[index] += 1; // Use strided access to create non-consecutive memory touches
        }
    }
}
