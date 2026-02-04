#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double jas_cmreal_t;

typedef struct {
    jas_cmreal_t *data;
    int size;
} jas_cmshapmatlut_t;

typedef struct {
    int mono;
    int order;
    int useluts;
    int usemat;
    jas_cmshapmatlut_t luts[3];
    jas_cmreal_t mat[3][4];
} jas_cmshapmat_t;

extern int i;
extern int j;
extern jas_cmshapmat_t *shapmat;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Access via Index Mapping Array
    // Precompute linear indices and access indirectly to simulate irregular pattern
    int indices[12];
    int idx = 0;
    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 4; ++j) {
            indices[idx++] = i * 4 + j;
        }
    }
    double *mat_ptr = &shapmat->mat[0][0];
    for (i = 0; i < 12; ++i) {
        mat_ptr[indices[i]] = 0.;
    }
}
