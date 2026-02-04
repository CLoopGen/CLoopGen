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

        if (i && pdfa->indexes[i].next == next_val) {
            map[k] = i;
            continue;
        }

        if (!i) {
            search_first[val] = ++last;
            map[k] = last;
            pdfa->indexes[last] = pdfa->indexes[k];
            continue;
        }

        while (search_next[i] && pdfa->indexes[search_next[i]].next != next_val) {
            i = search_next[i];
        }

        i = search_next[i];
        if (i) {
            map[k] = i;
        } else {
            map[k] = last;
            pdfa->indexes[last] = pdfa->indexes[k];
        }
    }
}
