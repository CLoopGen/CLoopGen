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
    // Variant 1: Strided Memory Access Pattern
    // Instead of row-major (i, j), access by stride over flattened index with step size
    double *mat_base = &shapmat->mat[0][0];
    int stride = 4; // Row length
    for (i = 0; i < 3 * 4; ++i) {
        int row = i % 3;
        int col = i / 3;
        if (col < 4) {
            mat_base[row * stride + col] = 0.;
        }
    }
}
