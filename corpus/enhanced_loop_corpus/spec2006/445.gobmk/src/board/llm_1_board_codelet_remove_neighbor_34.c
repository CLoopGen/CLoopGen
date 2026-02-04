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
    for (k = 0; k < s->neighbors; k++) {
        int found = 0;
        for (int probe = k; probe <= k && !found && !done; probe++) {
            if (s->neighborlist[probe] == n) {
                (change_stack_pointer->address = &(s->neighborlist[s->neighbors - 1]), (change_stack_pointer++)->value = (s->neighborlist[s->neighbors - 1]));
                (change_stack_pointer->address = &(s->neighborlist[probe]), (change_stack_pointer++)->value = (s->neighborlist[probe]));
                (change_stack_pointer->address = &(s->neighbors), (change_stack_pointer++)->value = (s->neighbors));
                s->neighborlist[probe] = s->neighborlist[s->neighbors - 1];
                s->neighbors--;
                done = 1;
                found = 1;
            }
        }
        if (done) break;
    }
}
