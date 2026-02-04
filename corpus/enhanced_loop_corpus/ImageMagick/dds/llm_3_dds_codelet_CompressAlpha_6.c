#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t min;
extern  size_t max;
extern  size_t steps;
extern unsigned char codes[8];
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with increased stride
    // Access every second element in a forward pass, then handle remainder if needed
    // Simulates strided access pattern which may affect cache performance
    ssize_t stride = 2;
    ssize_t limit = ((ssize_t)steps - 1) / stride + 1;
    for (i = 1; i < limit; i++) {
        ssize_t index = i * stride;
        if (index < (ssize_t)steps)
            codes[index + 1] = (unsigned char)((((ssize_t)steps - index) * (ssize_t)min + index * (ssize_t)max) / (ssize_t)steps);
    }
    // Handle any leftover elements not covered by stride (optional cleanup pass)
    for (i = 2 * limit - 1; i < (ssize_t)steps; i++)
        codes[i + 1] = (unsigned char)((((ssize_t)steps - i) * (ssize_t)min + i * (ssize_t)max) / (ssize_t)steps);
}
