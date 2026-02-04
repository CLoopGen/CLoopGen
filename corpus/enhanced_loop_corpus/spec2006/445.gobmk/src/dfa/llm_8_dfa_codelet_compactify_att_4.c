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
for (k = 1; k <= save_last; k += 2) {
    int val_k = pdfa->indexes[k].val;
    int next_k = pdfa->indexes[k].next;
    int i = search_first[val_k];
    if (i == 0) {
        search_first[val_k] = ++last;
        map[k] = last;
        pdfa->indexes[last] = pdfa->indexes[k];
        if (k + 1 <= save_last) {
            int val_next = pdfa->indexes[k+1].val;
            int next_next = pdfa->indexes[k+1].next;
            int j = search_first[val_next];
            if (j == 0) {
                search_first[val_next] = ++last;
                map[k+1] = last;
                pdfa->indexes[last] = pdfa->indexes[k+1];
            } else {
                for (; j != 0 && pdfa->indexes[j].next != next_next; j = search_next[j]) {
                    if (search_next[j] == 0) {
                        search_next[j] = ++last;
                        j = 0;
                        break;
                    }
                }
                if (j) {
                    map[k+1] = j;
                } else {
                    map[k+1] = last;
                    pdfa->indexes[last] = pdfa->indexes[k+1];
                }
            }
        }
    } else {
        for (; i != 0 && pdfa->indexes[i].next != next_k; i = search_next[i]) {
            if (search_next[i] == 0) {
                search_next[i] = ++last;
                i = 0;
                break;
            }
        }
        if (i) {
            map[k] = i;
        } else {
            map[k] = last;
            pdfa->indexes[last] = pdfa->indexes[k];
        }
    }
}
}
