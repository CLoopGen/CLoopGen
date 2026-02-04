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
    int k;
    for (i = 1; i <= pdfa->last_state; i++) {
        k = state_from[i];
        pdfa->states[i].att = old_states[k].att;
        for (j = 0; j < 4; j++) {
            ((void)(0));
            pdfa->states[i].next[j] = state_to[old_states[k].next[j]];
        }
    }
}
