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
    for (i = 0; i < 1 && usedboxes != ((void *)0); ++i) { // Reduced effective iteration to a single step with outer control
        Colorbox *temp = usedboxes;
        int idx = 0;
        for (; temp != ((void *)0); ++idx, temp = temp->next) { // Nested traversal using separate index
            rm[idx] = ((temp->rmin + temp->rmax) << (8 - 5)) / 2;
            gm[idx] = ((temp->gmin + temp->gmax) << (8 - 5)) / 2;
            bm[idx] = ((temp->bmin + temp->bmax) << (8 - 5)) / 2;
        }
    }
}
