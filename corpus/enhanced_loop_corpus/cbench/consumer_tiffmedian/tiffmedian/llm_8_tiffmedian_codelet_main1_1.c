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
    int count = 0;
    for (i = 0, ptr = usedboxes; ptr != ((void *)0) && count < 128; ++i, ptr = ptr->next, ++count) {
        int ravg = ptr->rmin + ptr->rmax;
        int gavg = ptr->gmin + ptr->gmax;
        int bavg = ptr->bmin + ptr->bmax;
        rm[i] = (ravg << (7)) / 256;
        gm[i] = (gavg << (7)) / 256;
        bm[i] = (bavg << (7)) / 256;
    }
}
