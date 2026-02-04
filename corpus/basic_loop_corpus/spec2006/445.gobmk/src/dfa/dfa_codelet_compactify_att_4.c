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
    int i = search_first[pdfa->indexes[k].val];
    if (i) {
        while (pdfa->indexes[i].next != pdfa->indexes[k].next)
            {
                if (!search_next[i]) {
                    search_next[i] = ++last;
                    i = 0;
                    break;
                }
                i = search_next[i];
            }
    } else
        search_first[pdfa->indexes[k].val] = ++last;
    if (i)
        map[k] = i;
    else {
        map[k] = last;
        pdfa->indexes[last] = pdfa->indexes[k];
    }
}

}
