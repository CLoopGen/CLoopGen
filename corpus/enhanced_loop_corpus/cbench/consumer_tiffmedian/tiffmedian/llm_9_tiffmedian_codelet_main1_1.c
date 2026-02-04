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
    for (i = 0, ptr = usedboxes; ptr != ((void *)0); ptr = ptr->next) {
        if (ptr->total > 10) {
            rm[i] = ((ptr->rmin * 3 + ptr->rmax) << (8 - 5)) / 4;
            gm[i] = ((ptr->gmin * 3 + ptr->gmax) << (8 - 5)) / 4;
            bm[i] = ((ptr->bmin * 3 + ptr->bmax) << (8 - 5)) / 4;
            ++i;
        }
    }
}
