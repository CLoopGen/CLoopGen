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
int j;

jas_cmshapmat_t *shapmat;

void init_vars() {
    shapmat = (jas_cmshapmat_t*)calloc(1, sizeof(jas_cmshapmat_t));
    if (!shapmat) exit(1);

    shapmat->mono = 0;
    shapmat->order = 0;
    shapmat->useluts = 0;
    shapmat->usemat = 1;

    for (int k = 0; k < 3; ++k) {
        shapmat->luts[k].size = 0;
        shapmat->luts[k].data = NULL;
    }

    for (int i_init = 0; i_init < 3; ++i_init) {
        for (int j_init = 0; j_init < 4; ++j_init) {
            shapmat->mat[i_init][j_init] = 0.0;
        }
    }
}