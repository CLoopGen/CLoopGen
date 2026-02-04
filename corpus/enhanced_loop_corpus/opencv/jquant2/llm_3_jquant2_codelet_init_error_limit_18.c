#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *table;
extern int in;
extern int out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access
    // Access elements with a fixed stride (e.g., every 4th element) to simulate strided pattern
    const int stride = 4;
    for (; in < ((255 + 1) / 16) * 3; in++, out += (in & 1) ? 0 : 1) {
        table[in * stride] = out;
        table[-in * stride] = -out;
    }
}
