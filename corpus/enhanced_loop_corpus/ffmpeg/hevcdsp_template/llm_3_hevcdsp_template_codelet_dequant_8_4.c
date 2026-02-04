#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *coeffs;
extern int shift;
extern int x;
extern int y;
extern int size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using index mapping array
    int *indices = (int*)malloc(size * size * sizeof(int));
    if (!indices) return;
    for (int i = 0; i < size * size; i++) {
        indices[i] = (i * 7) % (size * size); // pseudo-randomized indirect indexing
    }
    int idx = 0;
    for (y = 0; y < size; y++) {
        for (x = 0; x < size; x++) {
            int mapped_index = indices[idx++];
            int16_t *target = coeffs + mapped_index;
            *target = (int16_t)((uint16_t)(*target) << -shift);
        }
    }
    free(indices);
}
