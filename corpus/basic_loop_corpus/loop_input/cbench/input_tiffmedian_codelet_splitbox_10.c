#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

int histogram[32][32][32];
Colorbox *ptr;
int *iptr;
int *histp;
int ir;
int ig;
int ib;

void init_vars() {
    // Initialize histogram with 32x32x32 = 32768 integers, ~128KB data
    memset(histogram, 1, sizeof(histogram));

    // Allocate and initialize the colorbox pointed to by ptr
    ptr = (Colorbox*)malloc(sizeof(Colorbox));
    if (!ptr) exit(1);

    // Set reasonable bounds within [0,31] to stay within histogram dimensions
    ptr->rmin = 4;
    ptr->rmax = 27;   // 24 iterations
    ptr->gmin = 3;
    ptr->gmax = 28;   // 26 iterations
    ptr->bmin = 2;
    ptr->bmax = 29;   // 28 iterations

    ptr->total = 0;
    ptr->next = NULL;
    ptr->prev = NULL;

    // Allocate and initialize histp array to accumulate results
    // Total outer loop iterations: (bmax - bmin + 1) = 28
    histp = (int*)calloc(32, sizeof(int));
    if (!histp) exit(1);
}