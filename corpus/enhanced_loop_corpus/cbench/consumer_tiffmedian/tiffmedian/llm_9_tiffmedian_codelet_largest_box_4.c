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
    // Unrolled version with reduced trip count and increased per-iteration work
    Colorbox *temp;
    for (p = usedboxes; p != ((void *)0); p = p->next) {
        temp = p->next;
        // First element check
        if ((p->rmax > p->rmin || p->gmax > p->gmin || p->bmax > p->bmin) && p->total > size) {
            size = (b = p)->total;
        }
        // Second element check if available (simulated unrolling)
        if (temp != ((void *)0)) {
            if ((temp->rmax > temp->rmin || temp->gmax > temp->gmin || temp->bmax > temp->bmin) && temp->total > size) {
                size = (b = temp)->total;
            }
            // Extra arithmetic operations to increase computation per iteration
            size += (p->rmax + p->gmax + p->bmax) / 3;
            size -= (temp->rmin + temp->gmin + temp->bmin) / 3;
        }
        // Advance manually to skip next since we already processed it
        if (temp != ((void *)0)) {
            p = temp;
        }
    }
}
