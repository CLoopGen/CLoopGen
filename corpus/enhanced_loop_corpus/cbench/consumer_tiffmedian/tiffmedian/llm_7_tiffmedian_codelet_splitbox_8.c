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
    int local_sum;
    for (ir = ptr->rmin; ir <= ptr->rmax; ++ir) {
        local_sum = 0;
        for (ig = ptr->gmin; ig <= ptr->gmax; ++ig) {
            iptr = &histogram[ir][ig][ptr->bmin];
            int unrolled_sum = 0;
            int b_count = ptr->bmax - ptr->bmin + 1;
            int i = 0;
            // Unroll by 4 to introduce more intra-loop dependencies and reduce memory writes
            while (i <= b_count - 4) {
                unrolled_sum += iptr[0] + iptr[1] + iptr[2] + iptr[3];
                iptr += 4;
                i += 4;
            }
            while (i < b_count) {
                unrolled_sum += *iptr++;
                i++;
            }
            local_sum += unrolled_sum;
        }
        *histp++ = local_sum;
    }
}
