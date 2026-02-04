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
    // Variant 2: Memory Access Pattern Modification - Consecutive access via linearized index traversal to improve cache locality
    int idx = 0;
    for (i = 0; i < 32; i += 2) {
        for (j = 0; j < 32; j += 2) {
            int chroma_index = idx++; // Sequential write into chroma array
            for (p = 0; p < 3; p++) {
                int src_offset = 32 * i + j;
                const uint8_t* src_plane = planes[p + 1];

                // Force consecutive memory layout interpretation by accessing all four samples in increasing order
                uint32_t sum = (uint32_t)src_plane[src_offset] +
                               src_plane[src_offset + 1] +
                               src_plane[src_offset + 32] +
                               src_plane[src_offset + 33];

                chroma[p][chroma_index] = sum / 4;
            }
        }
    }
}
