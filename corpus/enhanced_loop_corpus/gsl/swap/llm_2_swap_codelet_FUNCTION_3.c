#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t dest_size1;
extern  size_t dest_size2;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < dest_size1; i++) {
        size_t j, k;
        for (j = 0; j < dest_size2; j += 2) {  // Strided access: step by 2
            if (j + 1 < dest_size2) {
                // Simulate processing two elements at once (j and j+1)
                k = j + 1;
            }
        }
    }
}
