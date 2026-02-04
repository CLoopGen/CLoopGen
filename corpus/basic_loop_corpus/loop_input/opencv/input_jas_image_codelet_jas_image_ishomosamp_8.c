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
jas_image_coord_t hstep;
jas_image_coord_t vstep;
int result;
int i;

static jas_image_cmpt_t **alloc_cmpts(int n) {
    return (jas_image_cmpt_t **)calloc(n, sizeof(jas_image_cmpt_t *));
}

static jas_image_cmpt_t *alloc_component(jas_image_coord_t h, jas_image_coord_t v) {
    jas_image_cmpt_t *cmp = (jas_image_cmpt_t *)calloc(1, sizeof(jas_image_cmpt_t));
    cmp->hstep_ = h;
    cmp->vstep_ = v;
    return cmp;
}

void init_vars() {
    const int num_components = 1000000;
    hstep = 2;
    vstep = 2;
    result = 1;
    i = 0;

    image = (jas_image_t *)calloc(1, sizeof(jas_image_t));
    image->numcmpts_ = num_components;
    image->maxcmpts_ = num_components;
    image->cmpts_ = alloc_cmpts(num_components);

    for (int idx = 0; idx < num_components; ++idx) {
        image->cmpts_[idx] = alloc_component(hstep, vstep);
    }

    image->clrspc_ = 0;
    image->cmprof_ = 0;
    image->inmem_ = 1;
}