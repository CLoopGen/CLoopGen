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
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of accessing histogram with strided access via [ir][ig][ptr->bmin],
    // we precompute a linear index assuming row-major order for 32x32x32 array,
    // and traverse memory consecutively within inner loops.

    int *base = &histogram[0][0][0];
    int rsize = 32 * 32;
    int csize = 32;
    int r, g, b;
    int offset_rg;

    for (r = ptr->rmin; r <= ptr->rmax; ++r) {
        *histp = 0;
        for (g = ptr->gmin; g <= ptr->gmax; ++g) {
            // Compute base offset for [r][g][ptr->bmin] in flattened space
            offset_rg = r * rsize + g * csize + ptr->bmin;
            int *start = base + offset_rg;
            int count = ptr->bmax - ptr->bmin + 1;

            // Inner loop now accesses consecutive memory locations
            for (int i = 0; i < count; ++i) {
                *histp += start[i];
            }
        }
        histp++;
    }
}
