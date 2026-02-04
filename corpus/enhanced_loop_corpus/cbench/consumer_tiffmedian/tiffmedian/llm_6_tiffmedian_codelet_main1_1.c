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
    int index = 0;
    Colorbox *current = usedboxes;
    while (current != ((void *)0)) {
        rm[index] = ((current->rmin + current->rmax) << (8 - 5)) / 2;
        gm[index] = ((current->gmin + current->gmax) << (8 - 5)) / 2;
        bm[index] = ((current->bmin + current->bmax) << (8 - 5)) / 2;
        current = current->next;
        ++index;
    }
}
