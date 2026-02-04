#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

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

int histogram[32][32][32];
Colorbox *ptr;
int *iptr;
int *histp;
int ir;
int ig;
int ib;

void init_vars() {
    // Allocate and initialize the histogram with 32x32x32 = 32768 integers (~128KB)
    for (int i = 0; i < 32; ++i) {
        for (int j = 0; j < 32; ++j) {
            for (int k = 0; k < 32; ++k) {
                histogram[i][j][k] = rand() % 256;
            }
        }
    }

    // Allocate a single Colorbox
    ptr = (Colorbox*)malloc(sizeof(Colorbox));
    if (!ptr) return;

    // Set reasonable bounds within [0,31] to stay within histogram array limits
    ptr->rmin = 4;
    ptr->rmax = 27;  // 24 iterations
    ptr->gmin = 3;
    ptr->gmax = 28;  // 26 iterations
    ptr->bmin = 5;
    ptr->bmax = 29;  // 25 iterations
    ptr->total = 0;
    ptr->next = NULL;
    ptr->prev = NULL;

    // Allocate histp array: size based on number of g values (gmax - gmin + 1)
    // We'll allocate slightly more than needed to be safe
    int gsize = (ptr->gmax - ptr->gmin + 1) + 5;
    int *base_histp = (int*)calloc(gsize, sizeof(int));
    histp = base_histp;

    // Initialize iptr to null; will be set in loop
    iptr = NULL;

    // Ensure all scalar indices are initialized
    ir = ig = ib = 0;
}