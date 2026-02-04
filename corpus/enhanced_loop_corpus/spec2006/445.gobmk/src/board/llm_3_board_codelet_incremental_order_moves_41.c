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
    // Variant 2: Consecutive Forward Access with Local Array Copy
    // Improve spatial locality by copying neighbor indices into a local array first,
    // then iterating consecutively over the local copy to access string[] entries.
    int n = string[s].neighbors;
    int local_neighbors[160];
    
    // Copy neighbor list to promote consecutive memory access
    for (r = 0; r < n; r++) {
        local_neighbors[r] = string[s].neighborlist[r];
    }
    
    // Now process in consecutive order from local cache-friendly array
    for (r = 0; r < n; r++) {
        t = &string[local_neighbors[r]];
        if (t->liberties == 1)
            (*saved_stones) += t->size;
    }
}
