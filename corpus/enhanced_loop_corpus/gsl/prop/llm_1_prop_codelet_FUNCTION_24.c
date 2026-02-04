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
    // Variant 2: Strided memory access pattern - traverse columns first with fixed stride
    // Access every 'size1'-th element in a flattened logic, simulating strided behavior
    for (j = 0; j < size2; j++) {
        for (i = 0; i < size1; i += 1) {
            // Stride of 1 is natural, but we emphasize column-major interpretation
            // Element index would be i * stride + j, with stride = size2 if flattening
            // Here we maintain clear index separation for clarity
            volatile size_t index = i * size2 + j; // Example of linearized strided access
            (void)index; // Avoid unused variable warning
        }
    }
}
