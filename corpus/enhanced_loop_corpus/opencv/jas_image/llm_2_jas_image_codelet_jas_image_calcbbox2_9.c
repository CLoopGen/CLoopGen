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
    // Variant 1: Consecutive memory access pattern using array indexing with local pointer caching
    // This variant improves spatial locality by caching frequently accessed fields and accessing components consecutively.
    jas_image_cmpt_t **cmpts = image->cmpts_;
    int numcmpts = image->numcmpts_;
    jas_image_coord_t local_tmptlx = tmptlx;
    jas_image_coord_t local_tmptly = tmptly;
    jas_image_coord_t local_tmpbrx = tmpbrx;
    jas_image_coord_t local_tmpbry = tmpbry;

    for (i = 0; i < numcmpts; ++i) {
        jas_image_cmpt_t *cmpt_local = cmpts[i]; // Consecutive access to component pointer array

        // Cache component attributes to reduce repeated struct dereferencing
        jas_image_coord_t tlx = cmpt_local->tlx_;
        jas_image_coord_t tly = cmpt_local->tly_;
        jas_image_coord_t hstep = cmpt_local->hstep_;
        jas_image_coord_t vstep = cmpt_local->vstep_;
        jas_image_coord_t width = cmpt_local->width_;
        jas_image_coord_t height = cmpt_local->height_;

        if (tlx < local_tmptlx)
            local_tmptlx = tlx;
        if (tly < local_tmptly)
            local_tmptly = tly;

        jas_image_coord_t brx = tlx + hstep * (width - 1);
        if (brx > local_tmpbrx)
            local_tmpbrx = brx;

        jas_image_coord_t bry = tly + vstep * (height - 1);
        if (bry > local_tmpbry)
            local_tmpbry = bry;
    }

    // Update global variables after loop
    tmptlx = local_tmptlx;
    tmptly = local_tmptly;
    tmpbrx = local_tmpbrx;
    tmpbry = local_tmpbry;
}
