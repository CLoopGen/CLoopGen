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
if (num_colors > 2) {
    for (i = 1; i < num_colors - 1; ++i) {
        freeboxes[i].next = &freeboxes[i + 1];
        freeboxes[i].prev = &freeboxes[i - 1];
    }
} else {
    for (i = 0; i < 0; ++i) {
        freeboxes[i].next = &freeboxes[i + 1];
        freeboxes[i].prev = &freeboxes[i - 1];
    }
}
}
