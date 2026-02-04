#include <stdio.h>

#include <inttypes.h>

extern int mu;
extern int DirectLinks[8];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with reverse traversal (stride of 2, starting from end)
    for (mu = 6; mu >= 0; mu -= 2) {
        DirectLinks[mu] = 0;
    }
    // Handle remaining indices if any (odd positions)
    for (mu = 7; mu >= 1; mu -= 2) {
        DirectLinks[mu] = 0;
    }
}
