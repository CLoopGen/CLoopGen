#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t *lens;
extern unsigned int codes;
extern uint16_t *work;
extern unsigned int sym;
extern uint16_t offs[16];

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect memory access via index remapping
    // Use an auxiliary array to define access order (simulating indirect addressing)
    uint16_t *indices = (uint16_t*)malloc(codes * sizeof(uint16_t));
    if (!indices) return; // Handle allocation failure

    // Create reverse index mapping for indirect access
    for (unsigned int i = 0; i < codes; i++)
        indices[i] = codes - 1 - i;

    for (unsigned int i = 0; i < codes; i++) {
        sym = indices[i];
        if (lens[sym] != 0)
            work[offs[lens[sym]]++] = (uint16_t)sym;
    }

    free(indices);
}
