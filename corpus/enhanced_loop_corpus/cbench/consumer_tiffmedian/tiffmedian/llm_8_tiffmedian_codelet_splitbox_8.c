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



void loop() {
    // Variant 1: Increased computational intensity by unrolling the innermost loop by a factor of 2
    // and increasing arithmetic operations per iteration to simulate heavier computation.
    for (ir = ptr->rmin; ir <= ptr->rmax; ++ir) {
        *histp = 0;
        for (ig = ptr->gmin; ig <= ptr->gmax; ++ig) {
            iptr = &histogram[ir][ig][ptr->bmin];
            int temp_sum = 0;
            int bstep = 2;
            int bmin = ptr->bmin;
            int bmax = ptr->bmax;
            ib = bmin;
            // Unroll by 2 with cleanup
            for (; ib + 1 <= bmax; ib += bstep) {
                temp_sum += *iptr++;
                temp_sum += *iptr++;  // Two increments per iteration
            }
            // Handle remainder
            if (ib <= bmax) {
                temp_sum += *iptr++;
            }
            *histp += temp_sum;
        }
        histp++;
    }
}
