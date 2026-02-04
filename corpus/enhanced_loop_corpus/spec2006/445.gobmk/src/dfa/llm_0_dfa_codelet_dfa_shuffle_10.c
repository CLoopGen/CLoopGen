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
    old_states[i].att = pdfa->states[i].att;
    old_states[i].next[0] = pdfa->states[i].next[0];
    old_states[i].next[1] = pdfa->states[i].next[1];
    old_states[i].next[2] = pdfa->states[i].next[2];
    old_states[i].next[3] = pdfa->states[i].next[3];
}
}
