#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned short *lens;
extern unsigned int codes;
extern unsigned int sym;
extern unsigned short count[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index remapping array (simulated via pointer arithmetic)
    unsigned int *indices = (unsigned int*)malloc(codes * sizeof(unsigned int));
    if (!indices) return;
    for (unsigned int i = 0; i < codes; i++)
        indices[i] = (i * 37) % codes;  // Pseudo-random permutation of indices

    for (unsigned int i = 0; i < codes; i++) {
        unsigned int idx = indices[i];
        if (lens[idx] < 16)
            count[lens[idx]]++;
    }

    free(indices);
}
