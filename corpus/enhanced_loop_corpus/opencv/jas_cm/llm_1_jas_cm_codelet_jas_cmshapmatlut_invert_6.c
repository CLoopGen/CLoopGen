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
    for (j = 0; j < lut->size; ++j) {
        ay = lut->data[j];
        if (sy == ay) {
            k = j + 1;
            for (; k < lut->size; ++k) {
                by = lut->data[k];
                if (by != sy) {
                    --k;
                    ax = ((double)j) / (lut->size - 1);
                    bx = ((double)k) / (lut->size - 1);
                    sx = (ax + bx) / 2.;
                    break;
                }
            }
            if (k >= lut->size) {
                ax = ((double)j) / (lut->size - 1);
                sx = ax;
            }
            break;
        }
        if (j < lut->size - 1) {
            by = lut->data[j + 1];
            if (sy > ay && sy < by) {
                ax = ((double)j) / (lut->size - 1);
                bx = ((double)(j + 1)) / (lut->size - 1);
                sx = ax + (sy - ay) / (by - ay) * (bx - ax);
                break;
            }
        }
    }
    invlut->data[i] = sx;
}
}
