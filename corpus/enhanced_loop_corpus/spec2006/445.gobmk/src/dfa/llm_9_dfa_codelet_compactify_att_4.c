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
int stride = 4;
for (k = 1; k <= save_last; k++) {
    int base_val = pdfa->indexes[k].val;
    int target_next = pdfa->indexes[k].next;
    int idx = search_first[base_val];

    if (idx) {
        int found = 0;
        for (int step = 0; step < stride && idx != 0; step++) {
            if (pdfa->indexes[idx].next == target_next) {
                found = 1;
                break;
            }
            if (search_next[idx] == 0) {
                search_next[idx] = ++last;
                idx = 0;
                break;
            }
            idx = search_next[idx];
        }
        if (found) {
            map[k] = idx;
        } else {
            map[k] = last;
            pdfa->indexes[last] = pdfa->indexes[k];
        }
    } else {
        search_first[base_val] = ++last;
        map[k] = last;
        pdfa->indexes[last] = pdfa->indexes[k];
    }
}
}
