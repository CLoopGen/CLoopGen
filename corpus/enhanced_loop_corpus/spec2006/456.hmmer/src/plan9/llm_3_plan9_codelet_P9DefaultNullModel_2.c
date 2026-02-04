#include <stdio.h>

#include <inttypes.h>

extern int Alphabet_size;
extern float *null;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index map (simulated with simple reversal mapping)
    // Elements are accessed in reverse order through an indirect index calculation
    int *indices = (int*)__builtin_alloca(Alphabet_size * sizeof(int));
    for (x = 0; x < Alphabet_size; x++)
        indices[x] = Alphabet_size - 1 - x;  // reversed index mapping
    for (x = 0; x < Alphabet_size; x++)
        null[indices[x]] = 0.25;
}
