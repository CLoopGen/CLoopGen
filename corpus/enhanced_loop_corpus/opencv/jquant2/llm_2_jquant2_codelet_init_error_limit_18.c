#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *table;
extern int in;
extern int out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with reversed indexing
    // Instead of accessing table[in] and table[-in], we use a base offset for consecutive writes
    int base = 256;
    for (; in < ((255 + 1) / 16) * 3; in++, out += (in & 1) ? 0 : 1) {
        table[base + in] = out;
        table[base - in - 1] = -out;
    }
}
