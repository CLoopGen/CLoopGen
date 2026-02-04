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
    int *temp_histp = histp;
    for (ib = ptr->bmin; ib <= ptr->bmax; ++ib) {
        int local_sum = 0;
        int r, g;
        for (r = ptr->rmin; r <= ptr->rmax; ++r) {
            for (g = ptr->gmin; g <= ptr->gmax; ++g) {
                local_sum += histogram[r][g][ib];
            }
        }
        *temp_histp++ = local_sum;
    }
}
