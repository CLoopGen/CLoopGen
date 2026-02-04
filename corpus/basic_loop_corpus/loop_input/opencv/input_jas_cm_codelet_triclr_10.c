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

int i;
jas_cmshapmat_t *shapmat;

void init_vars() {
    shapmat = (jas_cmshapmat_t*)calloc(1, sizeof(jas_cmshapmat_t));
    if (!shapmat) exit(1);

    shapmat->mono = 0;
    shapmat->order = 0;
    shapmat->useluts = 0;
    shapmat->usemat = 1;

    for (int idx = 0; idx < 3; ++idx) {
        shapmat->luts[idx].size = 0;
        shapmat->luts[idx].data = NULL;
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            shapmat->mat[i][j] = (i == j) ? 1.0 : 0.0;
        }
    }
}