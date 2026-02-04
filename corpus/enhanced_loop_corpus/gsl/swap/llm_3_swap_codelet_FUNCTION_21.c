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
    for (j = 0; j < dest_size2; j += 2) {  // Strided access with step size 2
        size_t e1 = i * dest_size2 + j;
        size_t e2 = (j + 1 < dest_size2) ? e1 + 1 : e1;  // Handle boundary
        // Simulate strided memory access pattern, processing every second element
        volatile size_t dummy1 = e1;
        volatile size_t dummy2 = e2;
    }
}
}
