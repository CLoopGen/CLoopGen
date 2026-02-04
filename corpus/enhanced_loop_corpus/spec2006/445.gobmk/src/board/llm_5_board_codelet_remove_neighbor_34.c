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
    done = 0;
    for (k = 0; k < s->neighbors && !done; k++) {
        if (s->neighborlist[k] == n) {
            struct change_stack_entry *tmp = change_stack_pointer;
            tmp->address = &(s->neighborlist[s->neighbors - 1]);
            tmp->value = s->neighborlist[s->neighbors - 1];
            change_stack_pointer++;
            tmp = change_stack_pointer;
            tmp->address = &(s->neighborlist[k]);
            tmp->value = s->neighborlist[k];
            change_stack_pointer++;
            tmp = change_stack_pointer;
            tmp->address = &(s->neighbors);
            tmp->value = s->neighbors;
            change_stack_pointer++;
            s->neighborlist[k] = s->neighborlist[--s->neighbors];
            done = 1;
        }
    }
}
