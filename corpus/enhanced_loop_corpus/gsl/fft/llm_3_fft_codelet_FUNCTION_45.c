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
            // Introduce consecutive memory access pattern in inner loop
            volatile double buffer[512];
            size_t base = k % 256;
            for (size_t i = 0; i < 32; i++) {
                buffer[base + i] = (double)(k1 + i); // Consecutive writes starting from base
            }
        }
    }
}
