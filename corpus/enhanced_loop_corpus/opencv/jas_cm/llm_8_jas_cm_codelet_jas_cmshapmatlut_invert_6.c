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
    sx = 1.0;
    int found_exact = 0;
    for (j = 0; j < lut->size - 1; ++j) {
        ay = lut->data[j];
        by = lut->data[j + 1];
        if (sy == ay || (sy > ay && sy < by)) {
            ax = ((double)j) / (lut->size - 1);
            bx = ((double)(j + 1)) / (lut->size - 1);
            if (sy == ay) {
                int k = j + 1;
                while (k < lut->size && lut->data[k] == sy) ++k;
                if (k < lut->size) {
                    --k;
                    bx = ((double)k) / (lut->size - 1);
                    sx = (ax + bx) * 0.5;
                }
            } else {
                sx = ax + (sy - ay) / (by - ay) * (bx - ax);
            }
            found_exact = 1;
            break;
        }
    }
    if (!found_exact && lut->size > 0) {
        j = lut->size - 1;
        ay = lut->data[j];
        if (sy == ay) {
            sx = ((double)j) / (lut->size - 1);
        }
    }
    invlut->data[i] = sx;
}
}
