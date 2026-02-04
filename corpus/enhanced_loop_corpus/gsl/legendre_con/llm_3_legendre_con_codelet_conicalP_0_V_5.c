#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double tau;
extern double V[12];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index mapping array
    int indices[11];
    for (int j = 0; j < 11; j++) {
        indices[j] = j + 1; // Map: indices[0..10] = 1..11
    }
    for (i = 0; i < 11; i++) {
        int idx = indices[i]; // Indirect access via index array
        V[idx] = V[idx - 1] * tau;
    }
}
