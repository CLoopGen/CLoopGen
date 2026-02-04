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

extern int num_colors;
extern Colorbox *freeboxes;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 2; i < num_colors - 2; ++i) {
        freeboxes[i].next = &freeboxes[i + 2];
        freeboxes[i].prev = &freeboxes[i - 2];
        freeboxes[i].rmin = freeboxes[i-1].rmin + freeboxes[i+1].rmin;
        freeboxes[i].gmin = freeboxes[i-1].gmin + freeboxes[i+1].gmin;
        freeboxes[i].bmin = freeboxes[i-1].bmin + freeboxes[i+1].bmin;
    }
}
