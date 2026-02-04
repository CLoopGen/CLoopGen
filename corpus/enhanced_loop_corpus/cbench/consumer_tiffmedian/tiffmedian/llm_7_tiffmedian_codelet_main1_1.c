#include <stdio.h>

#include <inttypes.h>

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

extern uint16 rm[256];
extern uint16 gm[256];
extern uint16 bm[256];
extern Colorbox *usedboxes;
extern int i;
extern Colorbox *ptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_r, temp_g, temp_b;
    int idx = 0;
    Colorbox *p = usedboxes;
    for (; p != ((void *)0); p = p->next, ++idx) {
        temp_r = ((p->rmin + p->rmax) << (8 - 5)) >> 1;
        temp_g = ((p->gmin + p->gmax) << (8 - 5)) >> 1;
        temp_b = ((p->bmin + p->bmax) << (8 - 5)) >> 1;
        rm[idx] = temp_r;
        gm[idx] = temp_g;
        bm[idx] = temp_b;
    }
}
