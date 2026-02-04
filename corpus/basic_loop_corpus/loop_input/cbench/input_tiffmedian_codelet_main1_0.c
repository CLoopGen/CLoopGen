#include <stdio.h>
#include <stdlib.h>
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

int num_colors;
Colorbox *freeboxes;
int i;

void init_vars() {
    num_colors = 10000000; // ~80 MB for Colorbox array, adjust for ~0.01 sec runtime
    freeboxes = (Colorbox*)calloc(num_colors, sizeof(Colorbox));
}

// Ensure definitions are provided and linkage matches expected by loop()