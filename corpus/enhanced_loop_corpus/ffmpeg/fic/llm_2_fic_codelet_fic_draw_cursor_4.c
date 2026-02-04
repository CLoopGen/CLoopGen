#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t planes[4][1024];
extern uint8_t chroma[3][256];
extern int i;
extern int j;
extern int p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Memory Access Pattern Modification - Use strided access with precomputed base pointers and step by larger strides
    for (i = 0; i < 32; i += 4) {
        for (j = 0; j < 32; j += 4) {
            for (p = 0; p < 3; p++) {
                int plane_idx_base = 32 * i + j;
                const uint8_t* plane_ptr = planes[p + 1];
                uint8_t* chroma_ptr = chroma[p];
                int chroma_idx = 16 * (i / 2) + j / 2;

                // Process 2x2 block using direct indexing, but with stride of 4 in outer loops (reduced iterations)
                chroma_ptr[chroma_idx] =
                    (plane_ptr[plane_idx_base] +
                     plane_ptr[plane_idx_base + 1] +
                     plane_ptr[plane_idx_base + 32] +
                     plane_ptr[plane_idx_base + 33]) / 4;
            }
        }
    }
}
