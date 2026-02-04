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
extern jas_image_coord_t hstep;
extern jas_image_coord_t vstep;
extern int result;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    jas_image_cmpt_t **cmpts = image->cmpts_;
    int numcmpts = image->numcmpts_;
    for (i = 0; i < numcmpts; i += 2) {
        int end_index = i + 1;
        if (cmpts[i]->hstep_ != hstep || cmpts[i]->vstep_ != vstep) {
            result = 0;
            break;
        }
        if (end_index < numcmpts) {
            if (cmpts[end_index]->hstep_ != hstep || cmpts[end_index]->vstep_ != vstep) {
                result = 0;
                break;
            }
        }
    }
}
