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
    j = 0;
    // Introduce a pre-check to reduce redundant iterations and create a WAW-like dependency on sx
    if (sy <= lut->data[0]) {
        sx = 0.0;
    } else if (sy >= lut->data[lut->size - 1]) {
        sx = 1.0;
    } else {
        // Linear search with early exit, but now sx is only written once due to structured control flow
        for (j = 0; j < lut->size - 1; ++j) {
            ay = lut->data[j];
            by = lut->data[j + 1];
            if (sy == ay) {
                for (k = j + 1; k < lut->size; ++k) {
                    if (lut->data[k] != sy)
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
