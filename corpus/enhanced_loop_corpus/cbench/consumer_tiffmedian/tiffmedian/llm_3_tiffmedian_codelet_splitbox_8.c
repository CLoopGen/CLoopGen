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
    // Variant 2: Strided Memory Access Pattern with Fixed Stride
    // Modify access pattern to use a fixed stride across the red dimension,
    // simulating non-unit stride traversal. This variant intentionally steps
    // through the red channel with a larger stride (e.g., every 2nd valid bin),
    // creating a strided access pattern across the outermost dimension.

    int stride = 2;
    int r, g, b;
    int effective_rmin = ptr->rmin;
    int effective_rmax = (ptr->rmax % stride == 0) ? ptr->rmax : ptr->rmax - (ptr->rmax % stride);

    for (r = effective_rmin; r <= effective_rmax; r += stride) {
        *histp = 0;
        for (g = ptr->gmin; g <= ptr->gmax; ++g) {
            iptr = &histogram[r][g][ptr->bmin];  // Still uses original indexing but at strided r
            int count = ptr->bmax - ptr->bmin + 1;
            for (int i = 0; i < count; ++i) {
                *histp += iptr[i];
            }
        }
        histp++;
    }

    // Handle remaining r values if stride caused undercoverage
    for (r = effective_rmax + 1; r <= ptr->rmax; ++r) {
        *histp = 0;
        for (g = ptr->gmin; g <= ptr->gmax; ++g) {
            iptr = &histogram[r][g][ptr->bmin];
            for (b = ptr->bmin; b <= ptr->bmax; ++b)
                *histp += *iptr++;
        }
        histp++;
    }
}
