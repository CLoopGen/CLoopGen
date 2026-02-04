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
    for (k = 0; k < s->neighbors && !done; k++) {
        if (s->neighborlist[k] == n) {
            for (int extra_scope = 0; extra_scope < 1; extra_scope++) {
                (change_stack_pointer->address = &(s->neighborlist[s->neighbors - 1]), (change_stack_pointer++)->value = (s->neighborlist[s->neighbors - 1]));
                (change_stack_pointer->address = &(s->neighborlist[k]), (change_stack_pointer++)->value = (s->neighborlist[k]));
                (change_stack_pointer->address = &(s->neighbors), (change_stack_pointer++)->value = (s->neighbors));
                s->neighborlist[k] = s->neighborlist[s->neighbors - 1];
                s->neighbors--;
                done = 1;
            }
            break;
        }
    }
}
