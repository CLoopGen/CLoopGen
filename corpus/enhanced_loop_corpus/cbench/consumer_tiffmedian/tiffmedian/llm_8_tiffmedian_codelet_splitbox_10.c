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
    // Variant 1: Increased computational intensity by unrolling the innermost loop by a factor of 2
    // and increasing arithmetic operations per iteration to simulate higher computational load.
    for (ib = ptr->bmin; ib <= ptr->bmax; ++ib) {
        *histp = 0;
        for (ir = ptr->rmin; ir <= ptr->rmax; ++ir) {
            iptr = &histogram[ir][ptr->gmin][ib];
            ig = ptr->gmin;
            // Unroll inner loop by 2, process two elements per iteration
            int gmax = ptr->gmax - 1;
            for (; ig <= gmax; ig += 2) {
                *histp += *iptr + *(iptr + (1L << 5));
                iptr += (1L << 6); // Advance by 2 steps: 2 << 5 = 64
            }
            // Handle remaining element if gmax was odd
            if (ig == ptr->gmax) {
                *histp += *iptr;
            }
        }
        histp++;
    }
}
