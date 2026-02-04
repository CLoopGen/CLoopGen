#include <stdio.h>

#include <inttypes.h>

extern int *table;
extern int in;
extern int out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Lower computational intensity with increased trip count and simplified operations
    for (in = 0; in < ((255 + 1) / 8); in++, out++) {
        table[in] = out & 1;  // Reduced to a simple bitwise operation
        table[-in] = -(out & 1);
    }
}
