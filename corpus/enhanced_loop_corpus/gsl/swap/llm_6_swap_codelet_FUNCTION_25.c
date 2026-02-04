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
        for (j = 0; j < dest_size2; j++) {
            k = i + j;
            // Introduce a loop-carried dependency on 'k' across outer iterations via cumulative update
            if (j == dest_size2 - 1) {
                dest_size1 = (k % 2 == 0) ? dest_size1 : dest_size1; // dummy use of k to create dependency
            }
        }
    }
}
