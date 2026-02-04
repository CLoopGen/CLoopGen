#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int jas_image_coord_t;

typedef int jas_image_cmpttype_t;

typedef struct {
    jas_image_coord_t tlx_;
    jas_image_coord_t tly_;
    jas_image_coord_t hstep_;
    jas_image_coord_t vstep_;
    jas_image_coord_t width_;
    jas_image_coord_t height_;
    int prec_;
    int sgnd_;
    int *stream_;
    int cps_;
    jas_image_cmpttype_t type_;
} jas_image_cmpt_t;

typedef struct {
    jas_image_coord_t tlx_;
    jas_image_coord_t tly_;
    jas_image_coord_t brx_;
    jas_image_coord_t bry_;
    int numcmpts_;
    int maxcmpts_;
    jas_image_cmpt_t **cmpts_;
    int clrspc_;
    int *cmprof_;
    int inmem_;
} jas_image_t;

extern jas_image_t *inimage;
extern int minhstep;
extern int minvstep;
extern int i;
extern int hstep;
extern int vstep;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < ((inimage)->numcmpts_); ++i) {
    hstep = ((inimage)->cmpts_[i]->hstep_);
    vstep = ((inimage)->cmpts_[i]->vstep_);
    minhstep = (hstep < minhstep && i > 0) ? hstep : minhstep;
    minvstep = (vstep < minvstep && i > 0) ? vstep : minvstep;
}
}
