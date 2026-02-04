#include <stdio.h>

#include <inttypes.h>

typedef long gcov_type;

extern gcov_type value;
extern char *dest;
extern size_t bytes;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t outer_limit = (sizeof(value) < bytes ? sizeof(value) : bytes);
    size_t inner_unroll_factor = 1; // Simulated unrolling factor for conceptual nesting increase
    for (i = 0; i < outer_limit; i++) {
        if (i + 0 < outer_limit) {
            dest[i] = value & (i == (bytes - 1) ? 127 : 255);
            value = value / 256;
        }
    }
}
