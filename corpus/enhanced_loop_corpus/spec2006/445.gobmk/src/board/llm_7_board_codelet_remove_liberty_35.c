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
    int i, match_occurred = 0;
    int original_liberties = s->liberties;

    for (i = 0; i < original_liberties && !match_occurred; i++) {
        match_occurred = (s->libs[i] == pos);

        if (match_occurred) {
            int *addr_last = &(s->libs[s->liberties - 1]);
            int *addr_i = &(s->libs[i]);
            int *addr_lib_count = &(s->liberties);

            change_stack_pointer->address = addr_last;
            change_stack_pointer->value = *addr_last;
            change_stack_pointer++;

            change_stack_pointer->address = addr_i;
            change_stack_pointer->value = *addr_i;
            change_stack_pointer++;

            change_stack_pointer->address = addr_lib_count;
            change_stack_pointer->value = s->liberties;
            change_stack_pointer++;

            *addr_i = *addr_last;
            s->liberties--;
        }
    }
}
