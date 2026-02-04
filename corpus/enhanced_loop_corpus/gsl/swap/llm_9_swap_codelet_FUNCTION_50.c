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
    for (i = 0; i < size1 * 2; i += 2) {
        for (j = (i + 1) % size2; j < size2 && j < i + 5; j++) {
            volatile size_t dummy = i * j + i - j; // Add arithmetic operations to increase intensity
            (void)dummy;
        }
    }
}
