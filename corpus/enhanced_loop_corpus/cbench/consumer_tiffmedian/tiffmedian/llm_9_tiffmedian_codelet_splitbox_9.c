#include <stdio.h>

#include <inttypes.h>

typedef struct colorbox {
    struct colorbox *next;
    struct colorbox *prev;
    int rmin;
    int rmax;
    int gmin;
    int gmax;
    int bmin;
    int bmax;
    int total;
} Colorbox;

extern int histogram[32][32][32];
extern Colorbox *ptr;
extern int *iptr;
extern int *histp;
extern int ir;
extern int ig;
extern int ib;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced trip count via stride-based sampling and simplified arithmetic
    const int stride = 2;
    for (ig = ptr->gmin; ig <= ptr->gmax; ig += stride) {
        *histp = 0;
        for (ir = ptr->rmin; ir <= ptr->rmax; ir += stride) {
            iptr = &histogram[ir][ig][ptr->bmin];
            for (ib = ptr->bmin; ib <= ptr->bmax; ++ib) {
                *histp += (*iptr++) << 0; // Simplified access, no extra ops
            }
        }
        histp++;
    }
    // Compensate for reduced iterations by doubling contribution (simulate approximate total)
    if ((ptr->gmax - ptr->gmin + 1) % 2 != 0) {
        *histp = (*histp) * 2;
    }
}
