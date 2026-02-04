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
    // Variant 1: Consecutive memory access using pointer arithmetic for libs array
    int *lib_ptr = string[s].libs;
    for (k = 0; k < string[s].liberties && k < 20; k++) {
        change_stack_pointer->address = lib_ptr + k;
        (change_stack_pointer++)->value = *(lib_ptr + k);
    }
}
