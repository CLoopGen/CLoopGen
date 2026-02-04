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
int stride = 2;
minhstep = ((inimage)->cmpts_[1]->hstep_);
minvstep = ((inimage)->cmpts_[1]->vstep_);
for (i = 1; i + 1 < ((inimage)->numcmpts_); i += stride) {
    int next_hstep1 = ((inimage)->cmpts_[i]->hstep_);
    int next_vstep1 = ((inimage)->cmpts_[i]->vstep_);
    int next_hstep2 = ((inimage)->cmpts_[i+1]->hstep_);
    int next_vstep2 = ((inimage)->cmpts_[i+1]->vstep_);
    hstep = (next_hstep1 < next_hstep2) ? next_hstep1 : next_hstep2;
    vstep = (next_vstep1 < next_vstep2) ? next_vstep1 : next_vstep2;
    if (hstep < minhstep)
        minhstep = hstep;
    if (vstep < minvstep)
        minvstep = vstep;
}
if (i == ((inimage)->numcmpts_) - 1) {
    hstep = ((inimage)->cmpts_[i]->hstep_);
    vstep = ((inimage)->cmpts_[i]->vstep_);
    if (hstep < minhstep)
        minhstep = hstep;
    if (vstep < minvstep)
        minvstep = vstep;
}
}
