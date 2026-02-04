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
for (i = 0; i < invlut->size; ++i) {
    sy = ((double)i) / (invlut->size - 1);
    sx = 1.;
    int found_exact = 0;
    // Use strided access with step size 2 for initial scan, then refine if needed
    for (j = 0; j < lut->size; j += 2) {
        // Handle odd-sized lut by checking bounds
        if (j >= lut->size) break;
        ay = lut->data[j];
        if (sy == ay) {
            // Found exact match, now search forward consecutively for transition
            for (k = j + 1; k < lut->size; ++k) {
                by = lut->data[k];
                if (by != sy)
                    break;
            }
            if (k < lut->size) {
                --k;
                ax = ((double)j) / (lut->size - 1);
                bx = ((double)k) / (lut->size - 1);
                sx = (ax + bx) / 2.;
            }
            found_exact = 1;
            break;
        }
        // Check intermediate values between strided elements
        if (j > 0 && j < lut->size) {
            // Interpolate check using previous and current strided point
            jas_cmreal_t prev_y = lut->data[j - 1];
            if ((sy > prev_y && sy < ay) || (sy > ay && sy < prev_y)) {
                // Linear interpolation between j-1 and j
                ax = ((double)(j - 1)) / (lut->size - 1);
                bx = ((double)j) / (lut->size - 1);
                jas_cmreal_t delta_y = ay - prev_y;
                if (delta_y != 0.0) {
                    sx = ax + (sy - prev_y) / delta_y * (bx - ax);
                }
                found_exact = 1;
                break;
            }
        }
    }
    // If no match found in strided pass, do a fine-grained backward scan
    if (!found_exact) {
        for (j = 0; j < lut->size - 1; ++j) {
            ay = lut->data[j];
            by = lut->data[j + 1];
            if (sy > ay && sy < by) {
                ax = ((double)j) / (lut->size - 1);
                bx = ((double)j + 1) / (lut->size - 1);
                sx = ax + (sy - ay) / (by - ay) * (bx - ax);
                break;
            }
        }
    }
    invlut->data[i] = sx;
}
}
