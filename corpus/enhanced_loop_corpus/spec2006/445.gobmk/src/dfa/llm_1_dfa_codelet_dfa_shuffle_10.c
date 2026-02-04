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
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 1; i <= pdfa->last_state; i++) {
    for (int k = 0; k < 2; k++) {
        old_states[i].next[k] = pdfa->states[i].next[k];
        old_states[i].att = pdfa->states[i].att;
    }
    for (int k = 2; k < 4; k++) {
        old_states[i].next[k] = pdfa->states[i].next[k];
        old_states[i].att = pdfa->states[i].att;
    }
}
}
