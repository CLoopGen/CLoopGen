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
// Use indirect access via index remapping: reverse traversal order of lut
int* index_map = (int*)alloca(lut->size * sizeof(int));
for (int idx = 0; idx < lut->size; ++idx) {
    index_map[idx] = lut->size - 1 - idx; // Reverse mapping
}

for (i = 0; i < invlut->size; ++i) {
    sy = ((double)i) / (invlut->size - 1);
    sx = 1.;

    int prev_j = -1;
    for (int map_idx = 0; map_idx < lut->size; ++map_idx) {
        j = index_map[map_idx]; // Indirect access through reversed index
        ay = lut->data[j];

        if (sy == ay) {
            // Search forward in original order for change
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
            break;
        }

        // Track consecutive pairs in original data order
        if (prev_j != -1 && j < prev_j) { // Ensure we are moving backward in index but checking forward in value
            int orig_low = j;
            int orig_high = prev_j;
            if (orig_low + 1 == orig_high) {
                ay = lut->data[orig_low];
                by = lut->data[orig_high];
                if (sy > ay && sy < by) {
                    ax = ((double)orig_low) / (lut->size - 1);
                    bx = ((double)orig_high) / (lut->size - 1);
                    sx = ax + (sy - ay) / (by - ay) * (bx - ax);
                    break;
                }
            }
        }
        prev_j = j;
    }
    invlut->data[i] = sx;
}
}
