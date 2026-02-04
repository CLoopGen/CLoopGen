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

jas_image_t *image;
jas_image_cmpt_t *cmpt;
jas_image_coord_t tmptlx;
jas_image_coord_t tmptly;
jas_image_coord_t tmpbrx;
jas_image_coord_t tmpbry;
jas_image_coord_t t;
int i;

static jas_image_cmpt_t **create_cmpts_array(int num) {
    jas_image_cmpt_t **cmpts = (jas_image_cmpt_t **)calloc(num, sizeof(jas_image_cmpt_t *));
    for (int idx = 0; idx < num; ++idx) {
        cmpts[idx] = (jas_image_cmpt_t *)calloc(1, sizeof(jas_image_cmpt_t));
        cmpts[idx]->tlx_ = 1000 + idx * 10;
        cmpts[idx]->tly_ = 1000 + idx * 15;
        cmpts[idx]->hstep_ = 2 + (idx % 3);
        cmpts[idx]->vstep_ = 2 + ((idx + 1) % 3);
        cmpts[idx]->width_ = 10000 + idx * 100;
        cmpts[idx]->height_ = 10000 + idx * 100;
        cmpts[idx]->prec_ = 8;
        cmpts[idx]->sgnd_ = 0;
        cmpts[idx]->cps_ = 1;
        cmpts[idx]->type_ = 0;
        size_t stream_size = (size_t)cmpts[idx]->width_ * cmpts[idx]->height_;
        cmpts[idx]->stream_ = (int *)calloc(stream_size, sizeof(int));
    }
    return cmpts;
}

void init_vars() {
    const int num_components = 10000;

    image = (jas_image_t *)calloc(1, sizeof(jas_image_t));
    image->numcmpts_ = num_components;
    image->maxcmpts_ = num_components;
    image->cmpts_ = create_cmpts_array(num_components);
    image->tlx_ = 0;
    image->tly_ = 0;
    image->brx_ = 0;
    image->bry_ = 0;
    image->clrspc_ = 1;
    image->cmprof_ = (int *)calloc(1, sizeof(int));
    image->inmem_ = 1;

    cmpt = 0;
    tmptlx = 1000000;
    tmptly = 1000000;
    tmpbrx = -1000000;
    tmpbry = -1000000;
    t = 0;
    i = 0;
}