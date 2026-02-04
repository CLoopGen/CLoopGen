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
    for (i = 0; i < (size1 > size2 ? size1 / 2 : size1); i += 2) {
        // Reduced effective trip count by stepping with increment of 2 and simplified inner loop
        for (j = 0; j < size2; j++) {
            // Minimal arithmetic to reduce computational load
            if (i + j < size1 + size2) {
                volatile size_t temp = i ^ j;
                (void)temp;
            }
        }
    }
}
