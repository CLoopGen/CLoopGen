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
    // Variant 2: Consecutive Memory Access via Local Buffer (Indirect to Direct)
    // Preload neighbor pointers into a temporary array to enable consecutive access,
    // improving spatial locality and cache performance.
    struct string_data *temp_neighbors[160];
    int count = string[s].neighbors;
    
    // Stage 1: Gather neighbor pointers consecutively
    for (r = 0; r < count; r++) {
        temp_neighbors[r] = &string[string[s].neighborlist[r]];
    }
    
    // Stage 2: Iterate through gathered pointers with consecutive memory access
    for (r = 0; r < count; r++) {
        t = temp_neighbors[r];
        if (t->liberties == 1)
            (*saved_stones) += t->size;
    }
}
