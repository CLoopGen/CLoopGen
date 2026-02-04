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
    // Variant 1: Consecutive Memory Access via Flattened Indexing
    // Instead of strided access using bit shifts, we calculate a flat index
    // to access histogram elements consecutively in memory where possible.
    int *base_hist = &histogram[0][0][0];
    int gmin = ptr->gmin;
    int gmax = ptr->gmax;
    int rmin = ptr->rmin;
    int rmax = ptr->rmax;
    int bmin = ptr->bmin;
    int bmax = ptr->bmax;
    
    for (ib = bmin; ib <= bmax; ++ib) {
        *histp = 0;
        for (ir = rmin; ir <= rmax; ++ir) {
            int offset = (ir << 10) + (gmin << 5) + ib;  // Precompute base offset: [ir][gmin][ib]
            iptr = base_hist + offset;
            for (ig = gmin; ig <= gmax; ++ig) {
                *histp += *iptr;
                iptr += (1 << 5);  // Still stride by 32 in flattened layout (due to g-dimension)
            }
        }
        histp++;
    }
}
