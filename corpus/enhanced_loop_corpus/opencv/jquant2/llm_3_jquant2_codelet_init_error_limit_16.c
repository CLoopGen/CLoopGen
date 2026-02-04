#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *table;
extern int in;
extern int out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive memory access using pointer arithmetic and reversed output mapping
    int *t = table + 128;  // Center the access point to allow negative indices safely
    int limit = (255 + 1) / 16;
    for (in = 0; in < limit; in++, out++) {
        t[in] = out;
        t[in + 1] = -out;  // Consecutive writes for positive and negative values
    }
}
