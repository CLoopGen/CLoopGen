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
int i, j;
for (i = 0; i < 6; ++i) {
    int idx = i % 3;
    shapmat->mat[idx][0] = (jas_cmreal_t)(idx + 1);
    shapmat->mat[idx][1] = (jas_cmreal_t)((idx + 1) * 2);
    if (i < 3) {
        shapmat->mat[idx][2] = (jas_cmreal_t)((idx + 1) * 3);
        shapmat->mat[idx][3] = (jas_cmreal_t)((idx + 1) * 4);
    }
}
}
