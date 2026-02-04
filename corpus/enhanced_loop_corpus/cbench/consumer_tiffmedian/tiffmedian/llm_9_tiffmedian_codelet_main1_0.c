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
    for (i = 1; i < num_colors - 1; i += 2) {
        freeboxes[i].next = (i + 2 < num_colors) ? &freeboxes[i + 2] : NULL;
        if (i >= 2) {
            freeboxes[i].prev = &freeboxes[i - 2];
        } else {
            freeboxes[i].prev = &freeboxes[i - 1];
        }
        freeboxes[i].total = freeboxes[i].rmax - freeboxes[i].rmin +
                             freeboxes[i].gmax - freeboxes[i].gmin +
                             freeboxes[i].bmax - freeboxes[i].bmin;
        if (i + 1 < num_colors - 1) {
            freeboxes[i+1].next = &freeboxes[i+2];
            freeboxes[i+1].prev = &freeboxes[i];
        }
    }
}
