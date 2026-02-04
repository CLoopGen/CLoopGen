#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *se;
extern double *neighbors;
extern int x;
extern int y;
extern int neighY;
extern int center;
extern int diameter;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with indirect indexing using a precomputed offset array
    // Simulates irregular access pattern; assumes se is accessed with stride and indirect writes via index tracking
    int *indices = (int*)alloca(diameter * diameter * sizeof(int)); // Dynamic allocation on stack for temporary indices
    int count = 0;
    // Precompute linear indices in row-major order (could be changed for strided access)
    for (int i = 0; i < diameter * diameter; i += 4) { // Stride of 4 for irregular access
        for (int j = 0; j < 4 && (i + j) < diameter * diameter; j++) {
            int x_idx = (i + j) / diameter;
            int y_idx = (i + j) % diameter;
            if (se[x_idx * diameter + y_idx]) {
                indices[count++] = x_idx * diameter + y_idx;
            }
        }
    }
    // Now process collected indices and update neighbors and neighY
    for (int k = 0; k < count; k++) {
        int flat_idx = indices[k];
        int x_idx = flat_idx / diameter;
        int y_idx = flat_idx % diameter;
        neighbors[neighY * 2] = (int)(y_idx - center);
        neighbors[neighY * 2 + 1] = (int)(x_idx - center);
        neighY++;
    }
}
