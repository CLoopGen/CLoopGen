#include <stdio.h>

#include <inttypes.h>

extern int mu;
extern int DirectLinks[8];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index mapping array
    int indices[8] = {7, 6, 5, 4, 3, 2, 1, 0}; // Reverse order access
    for (mu = 0; mu < 8; mu++) {
        DirectLinks[indices[mu]] = 0;
    }
}
