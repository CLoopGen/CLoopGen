#include <stdio.h>

#include <inttypes.h>

extern int *table;
extern int in;
extern int out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational intensity with simplified control flow and halved trip count
    for (; in < ((255 + 1) / 32) * 3; in += 2, out += 1) {
        table[in] = out;
        table[in + 1] = out;      // Duplicate assignment to reduce conditional checks
        table[-in] = -out;
        table[-(in + 1)] = -out;
    }
}
