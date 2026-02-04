#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double jas_cmreal_t;

typedef struct {
    jas_cmreal_t *data;
    int size;
} jas_cmshapmatlut_t;

typedef uint_fast32_t jas_iccuint32_t;

typedef uint_fast16_t jas_iccuint16_t;

typedef struct {
    jas_iccuint32_t numents;
    jas_iccuint16_t *ents;
} jas_icccurv_t;

extern jas_cmshapmatlut_t *lut;
extern jas_icccurv_t *curv;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    int stride = 2;
    int n = lut->size;
    for (i = 0; i < n; i += stride) {
        lut->data[i] = curv->ents[i] / 65535.;
        if (i + 1 < n) {
            lut->data[i + 1] = curv->ents[i + 1] / 65535.;
        }
    }
}
