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
for (cmptno = 0 , cmptparm = cmptparms; cmptno < numcmpts; ++cmptno , ++cmptparm) {
    jas_image_coord_t area = cmptparm->width * cmptparm->height;
    uint_fast32_t bytes_per_sample = (cmptparm->prec + 7) / 8;
    for (int i = 0; i < 2; ++i) {
        rawsize += area * bytes_per_sample;
    }
}
}
