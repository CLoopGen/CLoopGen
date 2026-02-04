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

extern jas_image_t *image;
extern jas_image_cmpt_t *cmpt;
extern jas_image_coord_t tmptlx;
extern jas_image_coord_t tmptly;
extern jas_image_coord_t tmpbrx;
extern jas_image_coord_t tmpbry;
extern jas_image_coord_t t;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < image->numcmpts_; ++i) {
    cmpt = image->cmpts_[i];
    if (!(cmpt->tlx_ >= tmptlx)) {
        tmptlx = cmpt->tlx_;
    }
    if (!(cmpt->tly_ >= tmptly)) {
        tmptly = cmpt->tly_;
    }
    t = cmpt->tlx_ + cmpt->hstep_ * (cmpt->width_ - 1);
    if (!(t <= tmpbrx)) {
        tmpbrx = t;
    }
    t = cmpt->tly_ + cmpt->vstep_ * (cmpt->height_ - 1);
    if (!(t <= tmpbry)) {
        tmpbry = t;
    }
}
}
