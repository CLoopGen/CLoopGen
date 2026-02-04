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
for (ib = ptr->bmin; ib <= ptr->bmax; ++ib) {
    *histp = 0;
    for (ir = ptr->rmin; ir <= ptr->rmax; ++ir) {
        iptr = &histogram[ir][ptr->gmin][ib];
        for (ig = ptr->gmin; ig <= ptr->gmax; ++ig) {
            *histp += *iptr;
            iptr += (1L << 5);
            continue;
        }
    }
    histp++;
}
}
