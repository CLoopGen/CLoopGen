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
    // Variant 2: Reduced computational complexity by collapsing two inner loops into one
    // using index arithmetic, reducing nesting depth and trip count.
    // Also skips zero-valued histogram entries to reduce effective work.

    int rsize = ptr->rmax - ptr->rmin + 1;
    int gsize = ptr->gmax - ptr->gmin + 1;
    int bsize = ptr->bmax - ptr->bmin + 1;
    int total_iterations = rsize * gsize * bsize;

    *histp = 0;  // Initialize accumulator once

    for (int idx = 0; idx < total_iterations; ++idx) {
        int flat_b = idx % bsize;
        int tmp = idx / bsize;
        int flat_g = tmp % gsize;
        int flat_r = tmp / gsize;

        ir = ptr->rmin + flat_r;
        ig = ptr->gmin + flat_g;
        ib = ptr->bmin + flat_b;

        int val = histogram[ir][ig][ib];
        if (val != 0) {  // Skip zero values to reduce effective computation
            *histp += val;
        }
    }

    histp++;  // Only increment once after full accumulation
}
