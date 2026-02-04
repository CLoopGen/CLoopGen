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



void loop() {
    // Introduce artificial loop-carried dependency via cumulative index shifting
    int idx = 0;
    jas_image_coord_t acc_t = 0;  // Accumulator with loop-carried dependence

    for (i = 0; i < image->numcmpts_; ++i) {
        idx = (idx + i) & (image->maxcmpts_ > 0 ? image->maxcmpts_ - 1 : 0);  // Artificial RAW/WAW dependence
        if (idx >= image->numcmpts_) idx = image->numcmpts_ - 1;

        cmpt = image->cmpts_[idx];

        // Create a chain of data flow using previous 'acc_t' value (introduces loop-carried RAW)
        t = acc_t + cmpt->tlx_ + cmpt->hstep_ * (cmpt->width_ - 1);
        acc_t = t;  // Feed output back (creates strong loop-carried RAW)

        // Maintain original logic but use derived t values
        if (cmpt->tlx_ < tmptlx)
            tmptlx = cmpt->tlx_;
        if (cmpt->tly_ < tmptly)
            tmptly = cmpt->tly_;

        if (t > tmpbrx)
            tmpbrx = t;

        t = cmpt->tly_ + cmpt->vstep_ * (cmpt->height_ - 1) + (acc_t % 2);  // Slight variation with dependence
        if (t > tmpbry)
            tmpbry = t;
    }
}
