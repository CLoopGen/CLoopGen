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
int pos;
int k;
struct string_data *s;

void init_vars() {
    // Allocate s on heap with meaningful initial values
    s = (struct string_data *)calloc(1, sizeof(struct string_data));
    s->liberties = 15;  // Set to valid value within array bounds [0,20)
    s->color = 1;
    s->size = 10;
    s->origin = 0;
    s->neighbors = 8;
    s->mark = 0;

    // Initialize libs array with unique values
    for (int i = 0; i < 20; i++) {
        s->libs[i] = i * 10 + 5;
    }

    // Set pos to match one of the libs entries to trigger the condition
    pos = s->libs[7];  // Will match at k=7

    // Allocate a sufficiently large change stack to avoid overflow during test
    // Use ~128MB total data to meet timing target (~0.01 sec on modern CPU)
    const size_t total_size = 128 * (1 << 20); // 128 MiB
    const size_t entry_count = total_size / sizeof(struct change_stack_entry);
    
    struct change_stack_entry *stack_mem = 
        (struct change_stack_entry *)calloc(entry_count, sizeof(struct change_stack_entry));
    
    change_stack_pointer = stack_mem;
}