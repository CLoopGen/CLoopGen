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
    // Variant 1: Consecutive memory access pattern using pointer arithmetic
    int *neighbor_ptr = s->neighborlist;
    for (k = 0; k < s->neighbors; k++) {
        if (*(neighbor_ptr + k) == n) {
            (change_stack_pointer->address = &(neighbor_ptr[s->neighbors - 1]), (change_stack_pointer++)->value = neighbor_ptr[s->neighbors - 1]);
            (change_stack_pointer->address = &(neighbor_ptr[k]), (change_stack_pointer++)->value = neighbor_ptr[k]);
            (change_stack_pointer->address = &(s->neighbors), (change_stack_pointer++)->value = s->neighbors);
            neighbor_ptr[k] = neighbor_ptr[s->neighbors - 1];
            s->neighbors--;
            done = 1;
            break;
        }
    }
}
