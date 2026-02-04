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
extern int pos;
extern int k;
extern struct string_data *s;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int temp_liberties = s->liberties;
    int found_index = -1;

    for (k = 0; k < temp_liberties; k++) {
        if (s->libs[k] == pos) {
            found_index = k;
            break;
        }
    }

    if (found_index != -1) {
        int last_lib = s->libs[temp_liberties - 1];
        int current_lib = s->libs[found_index];

        (change_stack_pointer->address = &(s->libs[temp_liberties - 1]), (change_stack_pointer++)->value = last_lib);
        (change_stack_pointer->address = &(s->libs[found_index]), (change_stack_pointer++)->value = current_lib);
        (change_stack_pointer->address = &(s->liberties), (change_stack_pointer++)->value = temp_liberties);

        s->libs[found_index] = last_lib;
        s->liberties = temp_liberties - 1;
    }
}
