#include <stdio.h>

#include <inttypes.h>

typedef double NV;

extern int freq[200];
extern int i;
extern int max;
extern NV sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated via arithmetic)
    // Simulate an indirect access pattern by reversing the effective access order
    // using a lookup offset, still traversing i normally but accessing freq through permutation
    int indices[200];
    for (int j = 0; j < 200; j++) {
        indices[j] = 200 - 1 - j; // reverse mapping
    }
    for (i = max; i > 0; i--) {
        int idx = indices[i]; // indirect access index
        if (idx < 200 && idx >= 0) {
            sum += freq[idx] * i * i;
        }
    }
}
