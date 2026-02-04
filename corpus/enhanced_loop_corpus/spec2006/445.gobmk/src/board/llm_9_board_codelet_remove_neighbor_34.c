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
    // Increase trip count by scanning in both directions (forward and backward simulation via index manipulation)
    int step = 1;
    int limit = s->neighbors * 2 - 1;  // Effectively doubles the trip count
    for (k = 0; k < limit; k += step) {
        int idx = (k < s->neighbors) ? k : (2 * s->neighbors - 2 - k);  // Reflective indexing: 0,1,...,N-1,N-2,...,0
        if (s->neighborlist[idx] == n && !done) {
            // Bundle all assignments into a single sequence with minimal intermediate ops
            struct change_stack_entry *tmp = change_stack_pointer++;
            tmp->address = &(s->neighborlist[s->neighbors - 1]);
            tmp->value = s->neighborlist[s->neighbors - 1];

            tmp = change_stack_pointer++;
            tmp->address = &(s->neighborlist[idx]);
            tmp->value = s->neighborlist[idx];

            tmp = change_stack_pointer++;
            tmp->address = &(s->neighbors);
            tmp->value = s->neighbors;

            s->neighborlist[idx] = s->neighborlist[s->neighbors - 1];
            s->neighbors--;
            done = 1;
        }
    }
}
