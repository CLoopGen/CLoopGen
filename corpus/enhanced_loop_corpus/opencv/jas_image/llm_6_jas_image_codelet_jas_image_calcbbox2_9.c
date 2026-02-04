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
    jas_image_coord_t local_tlx = tmptlx;
    jas_image_coord_t local_tly = tmptly;
    jas_image_coord_t local_brx = tmpbrx;
    jas_image_coord_t local_bry = tmpbry;

    for (i = 0; i < image->numcmpts_; ++i) {
        cmpt = image->cmpts_[i];
        // Introduce temporary variables to remove immediate write-read dependencies on global vars
        jas_image_coord_t brx_candidate = cmpt->tlx_ + cmpt->hstep_ * (cmpt->width_ - 1);
        jas_image_coord_t bry_candidate = cmpt->tly_ + cmpt->vstep_ * (cmpt->height_ - 1);

        // Update local accumulators instead of globals directly (removes WAW and WAR dependencies)
        if (cmpt->tlx_ < local_tlx)
            local_tlx = cmpt->tlx_;
        if (cmpt->tly_ < local_tly)
            local_tly = cmpt->tly_;
        if (brx_candidate > local_brx)
            local_brx = brx_candidate;
        if (bry_candidate > local_bry)
            local_bry = bry_candidate;
    }

    // Write back to global outputs after loop (eliminates loop-carried dependence)
    tmptlx = local_tlx;
    tmptly = local_tly;
    tmpbrx = local_brx;
    tmpbry = local_bry;
}
