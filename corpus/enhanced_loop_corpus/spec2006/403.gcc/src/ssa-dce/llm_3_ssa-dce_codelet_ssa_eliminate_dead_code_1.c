#include <stdio.h>

#include <inttypes.h>

extern int n_basic_blocks;
extern int i;
extern int *pdom;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via an index array (simulated with arithmetic)
    // Using indirect pattern: access pdom[(i * 3) % n_basic_blocks] to simulate irregular access
    int stride = 3;
    for (i = 0; i < n_basic_blocks; ++i) {
        int idx = (i * stride) % n_basic_blocks;
        if (pdom[idx] == (-3))
            pdom[idx] = (-2);
    }
}
