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
extern struct state *old_states;
extern int *state_to;
extern int *state_from;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int i_start = 1;
int i_end = pdfa->last_state;
int stride = 2;
for (i = i_start; i <= i_end; i += stride) {
    for (j = 0; j < 4; j++) {
        ((void)(0));
        pdfa->states[i].next[j] = state_to[old_states[state_from[i]].next[j]];
        if (i + 1 <= i_end) {
            pdfa->states[i + 1].next[j] = state_to[old_states[state_from[i + 1]].next[j]];
        }
    }
    pdfa->states[i].att = old_states[state_from[i]].att;
    if (i + 1 <= i_end) {
        pdfa->states[i + 1].att = old_states[state_from[i + 1]].att;
    }
}
if (pdfa->last_state % 2 == 0) {
    for (j = 0; j < 4; j++) {
        ((void)(0));
        pdfa->states[pdfa->last_state].next[j] = state_to[old_states[state_from[pdfa->last_state]].next[j]];
    }
    pdfa->states[pdfa->last_state].att = old_states[state_from[pdfa->last_state]].att;
}
}
