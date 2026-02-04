#include <stdio.h>

#include <inttypes.h>

extern int nc;
extern int iroot;
extern int i;
extern long temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect access pattern using an index mapping array to simulate irregular access
    // Simulate indirect access via a lookup table (conceptually representative)
    int indices[256]; // Assuming nc is reasonably small, e.g., <= 256
    for (int j = 0; j < nc && j < 256; j++) {
        indices[j] = j + 1; // populate sequential indices
    }
    for (i = 0; i < nc - 1; i++) {
        temp *= iroot;
    }
}
