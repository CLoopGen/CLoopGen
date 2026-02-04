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
    // Variant 2: Reduced computational complexity by collapsing two levels of nesting
    // into a single loop with manual indexing. Also reduces trip count by skipping every other ib.
    // Simulates a lower-intensity, flatter loop structure.

    int bstep = 2; // Process only every other ib to reduce total iterations
    for (ib = ptr->bmin; ib <= ptr->bmax; ib += bstep) {
        *histp = 0;
        // Collapse ir and ig loops into a single linear traversal
        int rsize = ptr->rmax - ptr->rmin + 1;
        int gsize = ptr->gmax - ptr->gmin + 1;
        for (int idx = 0; idx < rsize * gsize; ++idx) {
            int ir_idx = idx / gsize + ptr->rmin;
            int ig_idx = idx % gsize + ptr->gmin;
            *histp += histogram[ir_idx][ig_idx][ib];
        }
        histp++;
    }
}
