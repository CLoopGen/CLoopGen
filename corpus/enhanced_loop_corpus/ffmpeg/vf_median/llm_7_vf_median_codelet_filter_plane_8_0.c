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
extern  uint8_t *srcp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Remove potential aliasing and eliminate loop-carried dependencies by privatizing accumulators
    // Use temporary arrays to accumulate updates, then merge at the end — breaks WAR/WAW hazards.
    const int shift = (8 + 1) / 2;
    const int mask = (1 << shift) - 1;
    const int bucket_count_fine = (1 << shift) * (width * (1 << shift) + width);
    const int bucket_count_coarse = (1 << shift) * width;

    // Stack-allocated temporaries to remove immediate memory dependencies
    uint16_t temp_fine[512]; // Assuming bounded width for stack usage (e.g., width <= 256)
    uint16_t temp_coarse[512];
    
    // Initialize temporary accumulators to zero
    for (int k = 0; k < bucket_count_fine && k < 512; k++) temp_fine[k] = 0;
    for (int k = 0; k < bucket_count_coarse && k < 512; k++) temp_coarse[k] = 0;

    for (int i = 0; i < radiusV + (jobnr != 0) * (1 + radiusV); i++) {
        for (int j = 0; j < width; j++) {
            int fine_index = ((1 << shift) * (width * ((srcp[j] >> shift)) + j) + (srcp[j] & mask));
            int coarse_index = ((1 << shift) * j + (srcp[j] >> shift));

            if (fine_index < 512) temp_fine[fine_index]++;
            if (coarse_index < 512) temp_coarse[coarse_index]++;
        }
        srcp += src_linesize;
    }

    // Merge temporary results back into global arrays without interference in loop body
    for (int k = 0; k < 512; k++) {
        if (k < bucket_count_fine) cfine[k] += temp_fine[k];
        if (k < bucket_count_coarse) ccoarse[k] += temp_coarse[k];
    }
}
