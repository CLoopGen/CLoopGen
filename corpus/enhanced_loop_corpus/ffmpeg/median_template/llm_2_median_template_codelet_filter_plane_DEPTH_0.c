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
    // Variant 1: Consecutive memory access by prefetching and flattening the 2D-like access into a 1D stride
    // Instead of jumping by src_linesize each outer iteration, we calculate total offset upfront
    // and access memory in a more cache-friendly, predictable pattern.
    uint16_t* base_srcp = srcp;
    ptrdiff_t total_offset = 0;
    for (int i = 0; i < radiusV + (jobnr != 0) * (1 + radiusV); i++) {
        for (int j = 0; j < width; j++) {
            // Simulate some consecutive-accessible work (e.g., reading elements in row)
            volatile uint16_t val = base_srcp[total_offset + j]; // Access within row
            (void)val;
        }
        total_offset += src_linesize;
    }
}
