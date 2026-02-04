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
        int next_target = pdfa->indexes[k].next;
        int *first_ptr = &search_first[val];
        int i = *first_ptr;

        if (i) {
            int found = 0;
            for (int step = 0; step < last && i != 0; step++) {
                if (pdfa->indexes[i].next == next_target) {
                    found = 1;
                    break;
                }
                int next_i = search_next[i];
                if (!next_i) break;
                i = next_i;
            }
            if (found)
                map[k] = i;
            else {
                search_next[i] = ++last;
                map[k] = last;
                pdfa->indexes[last] = pdfa->indexes[k];
            }
        } else {
            *first_ptr = ++last;
            map[k] = last;
            pdfa->indexes[last] = pdfa->indexes[k];
        }
    }
}
