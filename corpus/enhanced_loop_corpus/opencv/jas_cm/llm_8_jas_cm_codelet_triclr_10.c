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
int j;
for (i = 0; i < 6; ++i) {
    int idx = i / 2;
    if (idx < 3) {
        shapmat->mat[idx][3] = (jas_cmreal_t)(0.0);
    }
}
}
