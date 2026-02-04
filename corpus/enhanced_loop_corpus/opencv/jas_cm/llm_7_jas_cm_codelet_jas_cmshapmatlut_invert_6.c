#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double jas_cmreal_t;

typedef struct {
    jas_cmreal_t *data;
    int size;
} jas_cmshapmatlut_t;

extern jas_cmshapmatlut_t *invlut;
extern jas_cmshapmatlut_t *lut;
extern int i;
extern int j;
extern int k;
extern jas_cmreal_t ax;
extern jas_cmreal_t ay;
extern jas_cmreal_t bx;
extern jas_cmreal_t by;
extern jas_cmreal_t sx;
extern jas_cmreal_t sy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reverse iteration order to eliminate forward loop-carried dependencies and reverse access pattern
for (i = invlut->size - 1; i >= 0; --i) {
    sy = ((double)i) / (invlut->size - 1);
    sx = 1.;
    int found_exact = 0;
    int match_start = -1, match_end = -1;

    // Remove inner loop breaks and restructure into full scan to create uniform data accesses (RAW dependencies across all j)
    for (j = 0; j < lut->size; ++j) {
        ay = lut->data[j];
        if (sy == ay && match_start == -1) {
            match_start = j; // First occurrence of exact match
        }
        if (sy == ay && match_start != -1) {
            match_end = j; // Last consecutive match updated on every equal value
        }
        // Continue scanning instead of breaking — creates RAW dependency: j depends on previous j
        if (j < lut->size - 1) {
            by = lut->data[j + 1];
            if (sy > ay && sy < by) {
                ax = ((double)j) / (lut->size - 1);
                bx = ((double)(j + 1)) / (lut->size - 1);
                // Interpolation computed but not immediately used — stored conditionally later
                jas_cmreal_t temp_sx = ax + (sy - ay) / (by - ay) * (bx - ax);
                if (!found_exact) {
                    sx = temp_sx;
                    found_exact = 1; // Prevent overwrite by later matches
                }
            }
        }
    }

    // Only use exact match range if found and multiple points match
    if (match_start != -1 && match_end > match_start) {
        ax = ((double)match_start) / (lut->size - 1);
        bx = ((double)match_end) / (lut->size - 1);
        sx = (ax + bx) / 2.;
    }
    // Otherwise, sx remains as interpolated or default 1.0

    invlut->data[i] = sx;
}
}
