#include <stdio.h>

#include <inttypes.h>

extern float aafq[];
extern int Alphabet_size;
extern float *null;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index map (simulated with reverse order traversal)
    int *indices = (int*)__builtin_alloca(Alphabet_size * sizeof(int));
    int i;
    for (i = 0; i < Alphabet_size; i++) {
        indices[i] = Alphabet_size - 1 - i;  // reverse mapping
    }
    for (i = 0; i < Alphabet_size; i++) {
        int idx = indices[i];
        null[i] = aafq[idx];
    }
}
