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


struct change_stack_entry {
    int *address;
    int value;
};


extern struct string_data string[240];
extern struct change_stack_entry *change_stack_pointer;
extern int s;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Strided memory access — process every second element forward and backward to cover all within bounds
    int stride = 2;
    int max_libs = (string[s].liberties < 20) ? string[s].liberties : 20;
    
    // First pass: even indices
    for (k = 0; k < max_libs; k += stride) {
        change_stack_pointer->address = &(string[s].libs[k]);
        (change_stack_pointer++)->value = string[s].libs[k];
    }
    
    // Second pass: odd indices
    for (k = 1; k < max_libs; k += stride) {
        change_stack_pointer->address = &(string[s].libs[k]);
        (change_stack_pointer++)->value = string[s].libs[k];
    }
}
