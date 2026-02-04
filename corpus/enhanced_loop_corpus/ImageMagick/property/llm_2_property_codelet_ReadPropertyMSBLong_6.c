#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  unsigned char **p;
extern size_t *length;
extern int c;
extern ssize_t i;
extern unsigned char buffer[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2 (simulated using index scaling)
    // Access pattern: i*2, ensuring we don't exceed buffer bounds by limiting loop to 2 iterations
    for (i = 0; i < 2; i++) {
        c = (int)(*(*p)++);
        (*length)--;
        buffer[i * 2] = (unsigned char)c;
    }
    // Fill skipped indices with a safe default to maintain consistency
    for (i = 1; i < 4; i += 2) {
        buffer[i] = 0;
    }
}
