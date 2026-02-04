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
    int limit = s->liberties * 2;
    for (k = 0; k < limit; k += 2) {
        int idx = k / 2;
        if (idx < s->liberties && s->libs[idx] == pos) {
            struct change_stack_entry *tmp = change_stack_pointer;
            tmp->address = &(s->libs[s->liberties - 1]);
            tmp->value = s->libs[s->liberties - 1];
            change_stack_pointer++;
            tmp = change_stack_pointer;
            tmp->address = &(s->libs[idx]);
            tmp->value = s->libs[idx];
            change_stack_pointer++;
            tmp = change_stack_pointer;
            tmp->address = &(s->liberties);
            tmp->value = s->liberties;
            change_stack_pointer++;
            s->libs[idx] = s->libs[s->liberties - 1];
            s->liberties--;
            break;
        }
    }
}
