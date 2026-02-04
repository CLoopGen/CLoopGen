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
    // Variant 2: Strided Memory Access Pattern
    // Introduce a strided traversal of the `srcp` array to simulate non-unit stride access.
    // This changes the memory access pattern to every 2nd element, then handles remainder if needed.
    // The updates to cfine and ccoarse now follow irregular strides indirectly through j.

    const int shift = (9 + 1) / 2;  // Equals 5
    const int mask = (1 << shift) - 1;
    const int stride = 2;  // Stride factor for accessing srcp and j-loop
    uint16_t *local_srcp = srcp;

    for (int i = 0; i < radiusV + (jobnr != 0) * (1 + radiusV); i++) {
        // Strided forward pass: even indices
        for (int j = 0; j < width; j += stride) {
            uint16_t val = local_srcp[j];
            int high = val >> shift;
            int low = val & mask;

            // Indexing remains logically same but accessed less frequently per iteration
            cfine[((1 << shift) * (width * high + j) + low)]++;
            ccoarse[((1 << shift) * j + high)]++;
        }
        // Fill in the odd indices in a second pass (simulates more complex access)
        for (int j = 1; j < width; j += stride) {
            uint16_t val = local_srcp[j];
            int high = val >> shift;
            int low = val & mask;

            cfine[((1 << shift) * (width * high + j) + low)]++;
            ccoarse[((1 << shift) * j + high)]++;
        }
        local_srcp += src_linesize;
    }
}
