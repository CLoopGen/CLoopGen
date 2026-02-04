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
for (i = 0; i < invlut->size; i += 2) {
    for (int offset = 0; offset < 2; ++offset) {
        int idx = i + offset;
        if (idx >= invlut->size) continue;
        sy = ((double)idx) / (invlut->size - 1);
        sx = 1.0;
        int match_found = 0;
        for (j = 0; j < lut->size; ++j) {
            ay = lut->data[j];
            if (sy == ay) {
                for (k = j + 1; k < lut->size && lut->data[k] == sy; ++k);
                if (k < lut->size) {
                    ax = ((double)j) / (lut->size - 1);
                    bx = ((double)(k - 1)) / (lut->size - 1);
                    sx = 0.5 * (ax + bx);
                }
                match_found = 1;
                break;
            }
            if (j + 1 < lut->size) {
                by = lut->data[j + 1];
                if (sy > ay && sy < by) {
                    ax = (double)j / (lut->size - 1);
                    bx = (double)(j + 1) / (lut->size - 1);
                    sx = ax + (sy - ay) * (bx - ax) / (by - ay);
                    match_found = 1;
                    break;
                }
            }
        }
        invlut->data[idx] = sx;
    }
}
}
