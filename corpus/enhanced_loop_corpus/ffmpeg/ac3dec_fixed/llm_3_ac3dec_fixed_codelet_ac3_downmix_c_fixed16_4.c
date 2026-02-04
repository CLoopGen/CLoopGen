#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t **samples;
extern int16_t **matrix;
extern int in_ch;
extern int len;
extern int i;
extern int j;
extern int v0;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect (Indexed) Memory Access Pattern
    // Use an index map to access samples in a non-sequential, indirect manner.
    // This simulates scenarios where data access depends on runtime indices (e.g., sparse or reordered input).

    // Assume we have an index mapping for channels (could be permuted or filtered set)
    int idx_map[64]; // Local index remapping (assume in_ch <= 64)
    for (j = 0; j < in_ch; j++) {
        idx_map[j] = j; // Identity map initially, but structure allows arbitrary remapping
    }

    for (i = 0; i < len; i++) {
        v0 = 0;
        for (j = 0; j < in_ch; j++) {
            int mapped_j = idx_map[j]; // Indirect access index
            v0 += samples[mapped_j][i] * matrix[0][mapped_j];
        }
        samples[0][i] = (v0 + 2048) >> 12;
    }
}
