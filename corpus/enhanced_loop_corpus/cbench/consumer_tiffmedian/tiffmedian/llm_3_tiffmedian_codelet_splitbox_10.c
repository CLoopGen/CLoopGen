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
    // Variant 2: Indirect Memory Access via Lookup Table
    // Precompute addresses of accessed histogram elements to enable indirect pointer access.
    // This simulates a gather-style access pattern using a lookup table for active bins.
    int *base_hist = &histogram[0][0][0];
    int gmin = ptr->gmin;
    int gmax = ptr->gmax;
    int rmin = ptr->rmin;
    int rmax = ptr->rmax;
    int bmin = ptr->bmin;
    int bmax = ptr->bmax;
    int max_entries = (rmax - rmin + 1) * (gmax - gmin + 1);
    static int *lookup[32*32];  // Max 1024 entries for r,g pairs
    int count = 0;

    // Build indirect access table for fixed ib slice (will update per ib)
    for (ir = rmin; ir <= rmax; ++ir) {
        for (ig = gmin; ig <= gmax; ++ig) {
            lookup[count++] = base_hist + ((ir << 10) | (ig << 5) | ib);  // [ir][ig][ib] address
        }
    }

    for (ib = bmin; ib <= bmax; ++ib) {
        *histp = 0;
        // Update lookup table for current 'ib'
        count = 0;
        for (ir = rmin; ir <= rmax; ++ir) {
            for (ig = gmin; ig <= gmax; ++ig) {
                lookup[count++] = base_hist + ((ir << 10) | (ig << 5) | ib);
            }
        }
        // Perform indirect accumulation
        for (int i = 0; i < count; ++i) {
            *histp += *(lookup[i]);
        }
        histp++;
    }
}
