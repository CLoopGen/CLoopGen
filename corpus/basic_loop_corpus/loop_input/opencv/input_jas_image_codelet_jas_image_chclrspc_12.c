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

jas_image_t *inimage;
int minhstep;
int minvstep;
int i;
int hstep;
int vstep;

void init_vars() {
    const int num_components = 100000;
    minhstep = 1000;
    minvstep = 1000;

    jas_image_cmpt_t **components = (jas_image_cmpt_t **)calloc(num_components, sizeof(jas_image_cmpt_t *));
    for (int idx = 0; idx < num_components; ++idx) {
        components[idx] = (jas_image_cmpt_t *)calloc(1, sizeof(jas_image_cmpt_t));
        components[idx]->hstep_ = (idx % 999) + 1;
        components[idx]->vstep_ = (idx % 999) + 1;
        components[idx]->tlx_ = 0;
        components[idx]->tly_ = 0;
        components[idx]->width_ = 100;
        components[idx]->height_ = 100;
        components[idx]->prec_ = 8;
        components[idx]->sgnd_ = 0;
        components[idx]->cps_ = 1;
        components[idx]->type_ = 0;
        components[idx]->stream_ = NULL;
    }

    inimage = (jas_image_t *)calloc(1, sizeof(jas_image_t));
    inimage->numcmpts_ = num_components;
    inimage->maxcmpts_ = num_components;
    inimage->cmpts_ = components;
    inimage->tlx_ = 0;
    inimage->tly_ = 0;
    inimage->brx_ = 1000;
    inimage->bry_ = 1000;
    inimage->clrspc_ = 0;
    inimage->cmprof_ = NULL;
    inimage->inmem_ = 1;
}