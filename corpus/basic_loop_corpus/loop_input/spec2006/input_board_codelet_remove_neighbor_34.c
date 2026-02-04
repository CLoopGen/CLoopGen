#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

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

struct change_stack_entry *change_stack_pointer;
int n;
int k;
int done;
struct string_data *s;

void init_vars() {
    // Allocate s on heap to allow flexible initialization
    s = (struct string_data *)calloc(1, sizeof(struct string_data));
    
    // Set neighbors to a value within the bounds of neighborlist array
    s->neighbors = 100;  // Less than 160 to stay in bounds
    
    // Initialize neighborlist with distinct values
    for (int i = 0; i < s->neighbors; i++) {
        s->neighborlist[i] = i * 3 + 1;  // Populate with non-repeating pattern
    }

    // Set n to a value that exists in the first half of neighborlist
    n = s->neighborlist[50];

    // Initialize other fields (not critical for loop logic)
    s->color = 1;
    s->size = 10;
    s->origin = 0;
    s->liberties = 5;
    for (int i = 0; i < 20; i++) {
        s->libs[i] = i + 1;
    }
    s->mark = 0;

    // Allocate change_stack_pointer: estimate max changes needed
    change_stack_pointer = (struct change_stack_entry *)malloc(1000000 * sizeof(struct change_stack_entry));
    if (!change_stack_pointer) {
        exit(1);
    }

    // Initialize globals
    k = 0;
    done = 0;
}