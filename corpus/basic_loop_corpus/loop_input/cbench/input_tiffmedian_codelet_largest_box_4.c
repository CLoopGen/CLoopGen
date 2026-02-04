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

Colorbox *usedboxes = NULL;
Colorbox *p = NULL;
Colorbox *b = NULL;
int size = 0;

#define NUM_BOXES 100000

void init_vars() {
    size = 500; 
    
    Colorbox *boxes = (Colorbox*)calloc(NUM_BOXES, sizeof(Colorbox));
    
    for (int i = 0; i < NUM_BOXES; i++) {
        boxes[i].rmin = i * 3 % 256;
        boxes[i].rmax = (i * 3 + 2) % 256;
        boxes[i].gmin = (i * 5) % 256;
        boxes[i].gmax = (i * 5 + 4) % 256;
        boxes[i].bmin = (i * 7) % 256;
        boxes[i].bmax = (i * 7 + 6) % 256;
        boxes[i].total = i * 10;
        
        if (i > 0) {
            boxes[i].prev = &boxes[i-1];
        } else {
            boxes[i].prev = NULL;
        }
        
        if (i < NUM_BOXES - 1) {
            boxes[i].next = &boxes[i+1];
        } else {
            boxes[i].next = NULL;
        }
    }
    
    usedboxes = &boxes[0];
}