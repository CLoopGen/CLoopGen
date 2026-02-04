#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int alphas[256];
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect array access using an index mapping (reverse traversal order)
    int indices[256];
    for (int i = 0; i < 256; ++i) {
        indices[i] = 255 - i;
    }
    for (n = 0; n < 256 && alphas[indices[n]] == 0; ++n) {
    }
    n = 256 - n; // Adjust n to reflect original logic's meaning (first index where alphas[n] != 0)
}
