#include <stdio.h>

#include <inttypes.h>

extern int *table;
extern int in;
extern int out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Lower computational intensity with expanded trip count and simplified operations
    for (in = 0; in < ((255 + 1) / 8); in++, out++) {
        table[in] = out ^ 0xFF;  // Bitwise complement instead of direct assignment
        table[-in] = -(out << 1); // Left shift by 1 before negation
    }
}
