#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int_fast32_t jas_image_coord_t;

typedef struct {
    jas_image_coord_t tlx;
    jas_image_coord_t tly;
    jas_image_coord_t hstep;
    jas_image_coord_t vstep;
    jas_image_coord_t width;
    jas_image_coord_t height;
    int prec;
    int sgnd;
} jas_image_cmptparm_t;

int numcmpts;
jas_image_cmptparm_t *cmptparms;
uint_fast32_t rawsize;
int cmptno;
jas_image_cmptparm_t *cmptparm;

void init_vars() {
    numcmpts = 1000000;
    cmptparms = (jas_image_cmptparm_t*)calloc(numcmpts, sizeof(jas_image_cmptparm_t));
    if (!cmptparms) exit(1);

    for (int i = 0; i < numcmpts; ++i) {
        cmptparms[i].width = 1;
        cmptparms[i].height = 1;
        cmptparms[i].prec = 8;
    }

    rawsize = 0;
    cmptno = 0;
    cmptparm = cmptparms;
}