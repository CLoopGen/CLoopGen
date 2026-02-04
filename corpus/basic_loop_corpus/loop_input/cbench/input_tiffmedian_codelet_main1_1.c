#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

typedef unsigned short uint16;

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

uint16 rm[256];
uint16 gm[256];
uint16 bm[256];
Colorbox *usedboxes;
int i;
Colorbox *ptr;

void init_vars() {
    const int num_boxes = 256;
    Colorbox *boxes = (Colorbox *)calloc(num_boxes, sizeof(Colorbox));
    if (!boxes) return;

    for (int idx = 0; idx < num_boxes; ++idx) {
        boxes[idx].rmin = (idx * 3) % 256;
        boxes[idx].rmax = (boxes[idx].rmin + (idx % 10) + 1) % 256;
        if (boxes[idx].rmax < boxes[idx].rmin) boxes[idx].rmax = boxes[idx].rmin + 1;

        boxes[idx].gmin = (idx * 7) % 256;
        boxes[idx].gmax = (boxes[idx].gmin + (idx % 12) + 1) % 256;
        if (boxes[idx].gmax < boxes[idx].gmin) boxes[idx].gmax = boxes[idx].gmin + 1;

        boxes[idx].bmin = (idx * 11) % 256;
        boxes[idx].bmax = (boxes[idx].bmin + (idx % 14) + 1) % 256;
        if (boxes[idx].bmax < boxes[idx].bmin) boxes[idx].bmax = boxes[idx].bmin + 1;

        boxes[idx].total = idx + 1;
        boxes[idx].prev = (idx == 0) ? NULL : &boxes[idx - 1];
        boxes[idx].next = (idx == num_boxes - 1) ? NULL : &boxes[idx + 1];
    }

    usedboxes = &boxes[0];
    i = 0;
    ptr = NULL;
}