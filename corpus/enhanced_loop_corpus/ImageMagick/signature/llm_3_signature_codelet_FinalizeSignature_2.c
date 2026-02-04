#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ssize_t i;
extern unsigned char *q;
extern unsigned int *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access - process every second element in p, double the step
    ssize_t count = 0;
    ssize_t stride = 2;
    ssize_t total_iterations = (32 / 4) / stride;
    for (i = 0; count < total_iterations; i += stride, count++) {
        unsigned int val = p[i];
        *q++ = (unsigned char)((val >> 24) & 255);
        *q++ = (unsigned char)((val >> 16) & 255);
        *q++ = (unsigned char)((val >> 8) & 255);
        *q++ = (unsigned char)(val & 255);
    }
    // Reset i to reflect number of processed elements if needed
    i = 0; // assuming external use does not depend on final i value; otherwise adjust accordingly
}
