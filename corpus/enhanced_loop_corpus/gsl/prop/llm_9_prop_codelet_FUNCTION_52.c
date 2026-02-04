#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t size1;
extern  size_t size2;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < size1 / 2; i++) {
        for (j = 0; j < size2 / 2; j++) {
            size_t temp = (i * j) + (i % 7) * (j % 11); // Increased arithmetic complexity per iteration
            temp ^= (temp << 2) | (temp >> 1);
        }
    }
}
