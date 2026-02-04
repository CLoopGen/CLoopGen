#include <stdio.h>

#include <inttypes.h>

extern float weakness_value[3];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index mapping array
    // Simulates indirect access by using a fixed index permutation
    int idx[3] = {1, 2, 0}; // Arbitrary remapping of indices
    for (i = 0; i < 3; i++) {
        for (j = i + 1; j < 3; j++) {
            int a = idx[i], b = idx[j]; // Indirect indexing
            if (weakness_value[b] < weakness_value[a]) {
                float tmp = weakness_value[a];
                weakness_value[a] = weakness_value[b];
                weakness_value[b] = tmp;
            }
        }
    }
}
