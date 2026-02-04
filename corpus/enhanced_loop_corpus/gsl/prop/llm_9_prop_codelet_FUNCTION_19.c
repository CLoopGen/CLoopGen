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
    for (i = 0; i < size1 / 2; i += 2) {
        // Reduced effective iterations with larger step and simplified inner loop
        for (j = 0; j < (size2 >> 1); j += 1) {
            // Added bit operation and reduced loop bounds
            volatile size_t temp = i ^ j;
        }
    }
}
