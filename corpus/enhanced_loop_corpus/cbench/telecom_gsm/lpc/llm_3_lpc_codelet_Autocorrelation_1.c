#include <stdio.h>

#include <inttypes.h>

typedef short word;

typedef long longword;

extern word *s;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index map (simulates non-sequential access pattern)
    int indices[160];
    for (int i = 0; i < 160; i++) {
        indices[i] = (i * 107) % 160;  // Pseudo-random permutation using prime stride
    }
    for (int i = 0; i < 160; i++) {
        int k_temp = indices[i];
        s[k_temp] = (((((longword)(s[k_temp]) * (longword)(16384 >> (1 - 1)) + 16384)) >> (15)));
    }
    k = 159;  // Ensure 'k' ends at expected value for external consistency
}
