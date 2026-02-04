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
        // Reduced effective trip count by stepping by 2 and dividing outer bound
        // Removed inner loop entirely, replacing with a single computation
        if (size2 > 0) {
            volatile size_t temp = i * i * i;  // Introduce cubic operation for different complexity profile
        }
    }
}
