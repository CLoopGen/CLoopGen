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
    jas_cmreal_t *data = lut->data;
    const jas_iccuint16_t *ents = curv->ents;
    int size = lut->size;
    jas_cmreal_t prev = 0.0;
    for (i = 0; i < size; ++i) {
        data[i] = (ents[i] / 65535.) + prev;
        prev = data[i];
    }
}
