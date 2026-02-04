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
        size_t j;
        for (j = 0; j < dest_size2; j++) {
            size_t e1 = i * dest_size2 + j;
            size_t e2 = e1 + 1;
            // Introduce RAW dependency: e2 depends on e1
            // Loop-carried dependence removed; all dependencies are within iteration
            if (e2 % 7 == 0) {
                e1 += 3;
            }
        }
    }
}
