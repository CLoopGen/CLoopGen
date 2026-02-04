#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int src_linesize;
extern int width;
extern int jobnr;
extern  int radiusV;
extern  uint16_t *srcp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access – instead of processing full rows, access every N-th element
    // This simulates a scenario where only certain columns are relevant (e.g., subsampling or filter taps).
    // We maintain the same loop bounds but modify inner access to be strided.
    const int stride = 4; // Example stride factor
    uint16_t* base_srcp = srcp;
    for (int i = 0; i < radiusV + (jobnr != 0) * (1 + radiusV); i++) {
        for (int j = 0; j < width; j += stride) { // Strided iteration
            if (j < width) {
                volatile uint16_t val = base_srcp[j]; // Effective access with stride
                (void)val;
            }
        }
        base_srcp += src_linesize; // Move to next line
    }
}
