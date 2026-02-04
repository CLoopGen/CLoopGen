#include <stdio.h>

#include <inttypes.h>

struct change_stack_entry {
    int *address;
    int value;
};


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


extern struct change_stack_entry *change_stack_pointer;
extern int n;
extern int k;
extern int done;
extern struct string_data *s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with reversed traversal (stride of -1)
    for (k = s->neighbors - 1; k >= 0; k--) {
        if (s->neighborlist[k] == n) {
            int last_idx = s->neighbors - 1;
            (change_stack_pointer->address = &(s->neighborlist[last_idx]), (change_stack_pointer++)->value = s->neighborlist[last_idx]);
            (change_stack_pointer->address = &(s->neighborlist[k]), (change_stack_pointer++)->value = s->neighborlist[k]);
            (change_stack_pointer->address = &(s->neighbors), (change_stack_pointer++)->value = s->neighbors);
            s->neighborlist[k] = s->neighborlist[last_idx];
            s->neighbors--;
            done = 1;
            break;
        }
    }
}
