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
extern jas_cmshapmat_t *shapmat;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive array traversal using a linearized index and indirect access via lookup table
    int indices[3] = {3, 7, 11}; // Precomputed column indices for mat[i][3] in row-major order
    jas_cmreal_t *mat_base = &shapmat->mat[0][0];
    for (i = 0; i < 3; ++i) {
        mat_base[indices[i]] = 0.;
    }
}
