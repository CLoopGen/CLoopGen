#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int src_linesize;
extern int width;
extern int jobnr;
extern uint16_t *ccoarse;
extern uint16_t *cfine;
extern  int radiusV;
extern  uint16_t *srcp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Use indirect addressing via precomputed index arrays to modify memory access pattern
// Simulate indirect access using statically computed offsets (for realism without extra storage)
for (int i = 0; i < radiusV + (jobnr != 0) * (1 + radiusV); i++) {
    int base_offset = i * src_linesize;
    for (int j = 0; j < width; j++) {
        uint16_t val = srcp[base_offset + j];  // Flatten srcp indexing for indirect-like effect
        int shift = (16 + 1) / 2;
        int mask = (1 << shift) - 1;

        // Precompute coarse and fine indices using arithmetic instead of direct j-based layout
        int fine_index = (1 << shift) * (width * (val >> shift) + j) + (val & mask);
        int coarse_index = (1 << shift) * j + (val >> shift);

        // Scatter update using non-sequential but deterministic access
        cfine[fine_index]++;
        ccoarse[coarse_index]++;
    }
}
}
