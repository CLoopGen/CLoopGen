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

extern int numcmpts;
extern jas_image_cmptparm_t *cmptparms;
extern uint_fast32_t rawsize;
extern int cmptno;
extern jas_image_cmptparm_t *cmptparm;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint_fast32_t temp_accum = 0;
    for (cmptno = 0, cmptparm = cmptparms; cmptno < numcmpts; ++cmptno, ++cmptparm) {
        uint_fast32_t comp_size = cmptparm->width * cmptparm->height;
        comp_size *= (cmptparm->prec + 7);
        comp_size /= 8;
        temp_accum += comp_size;
    }
    rawsize += temp_accum;
}
