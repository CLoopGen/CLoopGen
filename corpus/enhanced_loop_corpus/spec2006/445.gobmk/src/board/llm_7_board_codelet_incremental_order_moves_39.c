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
    int i;
    int local_saved = *saved_stones;
    for (r = 0; r < string[s].neighbors; r++) {
        t = &string[string[s].neighborlist[r]];
        if (t->liberties == 1) {
            local_saved += t->size;
            t->mark = 1; // Introduce WAW dependency: each iteration may overwrite mark
        }
    }
    *saved_stones = local_saved;
    // Add a second independent loop to eliminate loop-carried dependency on 'saved_stones'
    for (i = 0; i < string[s].neighbors; i++) {
        t = &string[string[s].neighborlist[i]];
        t->color = t->color; // Trivial self-read (RAW) to simulate data dependency
    }
}
