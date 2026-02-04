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



void loop(){
for (k = 0; k < s->liberties; k++) {
    if (s->libs[k] == pos) {
        int *target_addr_1 = &(s->libs[s->liberties - 1]);
        int *target_addr_2 = &(s->libs[k]);
        int *target_addr_3 = &(s->liberties);

        change_stack_pointer->address = target_addr_1;
        (change_stack_pointer++)->value = *target_addr_1;

        change_stack_pointer->address = target_addr_2;
        (change_stack_pointer++)->value = *target_addr_2;

        change_stack_pointer->address = target_addr_3;
        (change_stack_pointer++)->value = *target_addr_3;

        s->libs[k] = s->libs[s->liberties - 1];
        s->liberties--;
        break;
    }
}
}
