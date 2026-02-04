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
    // Introduce stride-based traversal over j to create strided memory accesses to srcp, cfine, and ccoarse.
    // This may improve cache behavior under certain access patterns or enable vectorization.
    uint16_t *srcp_local = srcp;
    int shift = (12 + 1) / 2;
    int mask = (1 << shift) - 1;
    int stride = 4;  // Chosen stride to promote data prefetching

    for (int i = 0; i < radiusV + (jobnr != 0) * (1 + radiusV); i++) {
        // Unroll and stride over j to generate strided access
        int j = 0;
        for (; j + stride <= width; j += stride) {
            for (int s = 0; s < stride; s++) {
                int idx = j + s;
                uint16_t val = srcp_local[idx];
                int high = val >> shift;
                int low = val & mask;

                // Strided access pattern affects both cfine and ccoarse indexing
                cfine[((1 << shift) * (width * high + idx) + low)]++;
                ccoarse[((1 << shift) * idx + high)]++;
            }
        }
        // Handle remainder
        for (; j < width; j++) {
            uint16_t val = srcp_local[j];
            int high = val >> shift;
            int low = val & mask;
            cfine[((1 << shift) * (width * high + j) + low)]++;
            ccoarse[((1 << shift) * j + high)]++;
        }
        srcp_local += src_linesize;
    }
}
