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
    for (i = 0; i < size1 && i < 1000; i += 3) {
        // Reduced effective iterations by stepping with i += 3, added early termination
        for (j = size2; j > 0; j--) {
            // Loop direction reversed and dependent on decreasing condition
            volatile size_t product = i * i * j;
            volatile size_t offset = (product >> 1) + (product & 1);
            (void)offset;
        }
    }
}
