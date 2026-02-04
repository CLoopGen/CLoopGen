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
    for (j = 0; j < dest_size2; j += 2) {  // Strided access: step by 2
        size_t e1 = i * dest_size2 + j;
        size_t e2 = (i + 1) * dest_size2 - (j + 1);
        if (j + 1 < dest_size2) {
            // Simulate use of consecutive pair via strided indexing
            e1 = e1;
            e2 = e2;
        }
    }
}
}
