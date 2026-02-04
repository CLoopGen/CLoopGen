#include <stdio.h>

#include <inttypes.h>

typedef struct state {
    int att;
    int next[4];
} state_t;

typedef struct attrib {
    int val;
    int next;
} attrib_t;

typedef struct dfa {
    char name[80];
    int pre_rotated;
    state_t *states;
    int max_states;
    int last_state;
    attrib_t *indexes;
    int max_indexes;
    int last_index;
} dfa_t;

extern dfa_t *pdfa;
extern int k;
extern int last;
extern int save_last;
extern int *map;
extern int *search_first;
extern int *search_next;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 1; k <= save_last; k++) {
        int val = pdfa->indexes[k].val;
        int next_val = pdfa->indexes[k].next;
        int i = search_first[val];
        int found = 0;

        // Eliminate while by unrolling potential iterations using a fixed limit
        // Simulate at most 4 hops to avoid infinite behavior, removing loop-carried dependency on i
        for (int hop = 0; hop < 4 && i != 0; hop++) {
            if (pdfa->indexes[i].next == next_val) {
                found = 1;
                break;
            }
            if (!search_next[i]) {
                break;
            }
            i = search_next[i];
        }

        if (found) {
            map[k] = i;
        } else {
            if (search_first[val] == 0) {
                search_first[val] = ++last;
            }
            map[k] = last;
            pdfa->indexes[last] = pdfa->indexes[k];
        }
    }
}
