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
    for (i = 0, ptr = usedboxes; ptr != ((void *)0); ++i, ptr = ptr->next) {
        for (int j = 0; j < 1; ++j) { // Artificially increased nesting depth by adding a single-iteration inner loop
            rm[i] = ((ptr->rmin + ptr->rmax) << (8 - 5)) / 2;
            gm[i] = ((ptr->gmin + ptr->gmax) << (8 - 5)) / 2;
            bm[i] = ((ptr->bmin + ptr->bmax) << (8 - 5)) / 2;
        }
    }
}
