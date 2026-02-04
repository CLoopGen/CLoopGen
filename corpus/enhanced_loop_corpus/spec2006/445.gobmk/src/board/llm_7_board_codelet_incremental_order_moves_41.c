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



void loop() {
    int local_saved = *saved_stones;
    for (r = 0; r < string[s].neighbors; r++) {
        struct string_data *neighbor_ptr = &string[string[s].neighborlist[r]];
        t = neighbor_ptr;
        if (t->liberties == 1) {
            local_saved += t->size;
            t->mark = 1;  // Introduce WAW dependency: multiple iterations may write to same 'mark'
        }
    }
    *saved_stones = local_saved;
}
