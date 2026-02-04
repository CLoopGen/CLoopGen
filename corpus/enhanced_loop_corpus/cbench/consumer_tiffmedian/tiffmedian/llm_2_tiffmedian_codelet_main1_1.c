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
    // Variant 1: Strided memory access with stride of 2 (writing every other element)
    // Remaining elements are left untouched; assumes array bounds are safe for stride
    int j = 0;
    for (i = 0, ptr = usedboxes; ptr != ((void *)0); ++i, ptr = ptr->next) {
        rm[j] = ((ptr->rmin + ptr->rmax) << (8 - 5)) / 2;
        gm[j] = ((ptr->gmin + ptr->gmax) << (8 - 5)) / 2;
        bm[j] = ((ptr->bmin + ptr->bmax) << (8 - 5)) / 2;
        j += 2; // Strided access: write to rm[0], rm[2], rm[4], etc.
    }
}
