#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef short J12SAMPLE;

extern J12SAMPLE *table12;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated with arithmetic)
    int indices[4] = {0, 1, 3, 2}; // Small permutation pattern
    for (i = 0; i <= 4095; i += 4) {
        for (int j = 0; j < 4; j++) {
            int idx = i + indices[j];
            if (idx <= 4095) {
                table12[idx] = (J12SAMPLE)idx;
            }
        }
    }
}
