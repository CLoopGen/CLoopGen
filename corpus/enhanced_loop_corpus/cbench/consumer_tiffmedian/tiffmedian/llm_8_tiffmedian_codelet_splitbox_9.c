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
    // Variant 1: Increased computational intensity by unrolling inner loop and adding redundant arithmetic operations
    for (ig = ptr->gmin; ig <= ptr->gmax; ++ig) {
        *histp = 0;
        for (ir = ptr->rmin; ir <= ptr->rmax; ++ir) {
            iptr = &histogram[ir][ig][ptr->bmin];
            int temp_sum = 0;
            int bstep;
            // Unroll by 4x with bounds check
            for (bstep = ptr->bmin; bstep + 3 <= ptr->bmax; bstep += 4) {
                temp_sum += *iptr++;
                temp_sum += *iptr++;
                temp_sum += *iptr++;
                temp_sum += *iptr++;
            }
            // Handle remainder
            for (; bstep <= ptr->bmax; ++bstep) {
                temp_sum += *iptr++;
            }
            *histp += temp_sum + (temp_sum >> 3); // Extra arithmetic: add 1/8 of sum to increase computation
        }
        histp++;
    }
}
