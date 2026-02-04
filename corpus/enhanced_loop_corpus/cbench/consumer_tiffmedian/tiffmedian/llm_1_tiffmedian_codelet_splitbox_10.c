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
*histp = 0;
for (ib = ptr->bmin; ib <= ptr->bmax; ++ib) {
    for (ir = ptr->rmin; ir <= ptr->rmax; ++ir) {
        iptr = &histogram[ir][ptr->gmin][ib];
        ig = ptr->gmin;
        *histp += *iptr;
        iptr += (1L << 5);
        ig++;
        if (ig <= ptr->gmax) {
            do {
                *histp += *iptr;
                iptr += (1L << 5);
                ig++;
            } while (ig <= ptr->gmax);
        }
    }
}
histp++;
}
