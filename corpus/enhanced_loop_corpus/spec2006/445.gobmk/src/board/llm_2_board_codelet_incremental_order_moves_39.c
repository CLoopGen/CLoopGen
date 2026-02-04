#include <stdio.h>

#include <inttypes.h>

struct string_data {
    int color;
    int size;
    int origin;
    int liberties;
    int libs[20];
    int neighbors;
    int neighborlist[160];
    int mark;
};


extern struct string_data string[240];
extern int *saved_stones;
extern int s;
extern int r;
extern struct string_data *t;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by prefetching and iterating through a local copy of neighbor pointers
    struct string_data *neighbor_ptrs[160];
    int num_neighbors = string[s].neighbors;
    
    // Precompute base addresses for consecutive access
    for (int i = 0; i < num_neighbors; i++) {
        neighbor_ptrs[i] = &string[string[s].neighborlist[i]];
    }

    for (int r = 0; r < num_neighbors; r++) {
        t = neighbor_ptrs[r];
        if (t->liberties == 1)
            (*saved_stones) += t->size;
    }
}
