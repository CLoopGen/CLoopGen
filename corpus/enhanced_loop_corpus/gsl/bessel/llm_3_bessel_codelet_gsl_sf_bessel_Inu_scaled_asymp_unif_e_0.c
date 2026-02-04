#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern double t;
extern double tpow[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index mapping array
    int indices[15];
    for (int j = 0; j < 15; j++) {
        indices[j] = j + 1;
    }
    // Shuffle pattern: even indices first, then odd (indirect access order)
    int temp[15], idx = 0;
    for (int j = 0; j < 15; j += 2) temp[idx++] = indices[j];
    for (int j = 1; j < 15; j += 2) temp[idx++] = indices[j];
    for (int k = 0; k < 15; k++) {
        i = temp[k];
        tpow[i] = t * tpow[i - 1];
    }
}
