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
    jas_cmreal_t *mat0 = shapmat->mat[0] + 3;
    jas_cmreal_t *mat1 = shapmat->mat[1] + 3;
    jas_cmreal_t *mat2 = shapmat->mat[2] + 3;
    *mat0 = 0.;
    *mat1 = 0.;
    *mat2 = 0.;
}
