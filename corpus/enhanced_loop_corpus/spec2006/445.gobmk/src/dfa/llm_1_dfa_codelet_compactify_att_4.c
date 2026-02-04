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
        int i = search_first[val];

        for (int found = i ? 1 : 0; found; ) {
            if (pdfa->indexes[i].next == next_target) {
                found = 0;
            } else if (search_next[i]) {
                i = search_next[i];
            } else {
                i = 0;
                search_next[0] = ++last;
                found = 0;
            }
        }

        if (!i) {
            i = ++last;
            search_first[val] = i;
            pdfa->indexes[i] = pdfa->indexes[k];
        }
        map[k] = i;
    }
}
