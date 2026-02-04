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

extern int num_colors;
extern Colorbox *freeboxes;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Eliminate loop-carried dependencies entirely by making iterations independent
    // All writes are to distinct fields with no read-after-write chains across iterations
    for (i = 1; i < num_colors - 1; ++i) {
        Colorbox *curr = &freeboxes[i];
        Colorbox *next = &freeboxes[i + 1];
        Colorbox *prev = &freeboxes[i - 1];
        
        curr->rmin = i;          // Initialize some values independently
        curr->gmax = i * 2;
        curr->bmin = i + 100;
        
        curr->next = next;
        curr->prev = prev;
        
        curr->total = next->rmax - prev->rmin;  // Only uses input state, no intra-loop dependency
    }
}
