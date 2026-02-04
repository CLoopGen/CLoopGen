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

extern Colorbox *usedboxes;
extern Colorbox *p;
extern Colorbox *b;
extern int size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (p = usedboxes; p != ((void *)0); p = p->next) {
        int condition1 = (p->rmax > p->rmin || p->gmax > p->gmin || p->bmax > p->bmin);
        int condition2 = (p->total > size);
        if (condition1 && condition2) {
            b = p;
            size = b->total;
        } else {
            continue;
        }
    }
}
